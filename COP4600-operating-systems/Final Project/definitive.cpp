#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include "SPI.h"
#include "SD.h"
#include "FS.h"
#include "pthread.h"
#include "FreeRTOSConfig.h"
#include "freertos/semphr.h"

#define BUFFER_SIZE 100 

SemaphoreHandle_t emptysema;
SemaphoreHandle_t full;
SemaphoreHandle_t mutex;

int in=0;
int out=0;
int count=0;


#define REASSIGN_PINS
int sck = 18;
int miso = 19;
int mosi = 23;
int cs = 5;

#define BNO055_SAMPLERATE_DELAY_MS (11)

unsigned long starttime; 
float starttimefloated;

File myFile;

float stdDevBNOx =0.011762;
float stdDevBNOy = 0.012779;
float stdDevBNOz = 0.039991;
float covariances = 0; 

float stdDevBNOVelx = 0.007591 * 0.007591; 
float stdDevBNOVely = 0.021781 * 0.021781;
float stdDevBNOVelz = 1.69478  * 1.69478;

float stdDevBNOPosx = 2.87 * 2.87;
float stdDevBNOPosy = 2.87 * 2.87;
float stdDevBNOPosz = 2.87 * 2.87;

float AvgErrorAccX = 0.046484;
float AvgErrorAccY = 0.133379; 
float AvgErrorAccZ = 0.044934;

float AvgErrorVelX = 5;
float AvgErrorVelY = 5;
float AvgErrorVelZ = 5;

float AvgErrorPosX = 25;
float AvgErrorPosY = 25;
float AvgErrorPosZ = 25;

float KGainx[2], KGainy[2], KGainz[2];


String LoggerFilename = "/ploutoun.txt";


class cartesianer{
  public:
    float x;
    float y;
    float z;
    float chronic;

    cartesianer() : x(0.0), y(0.0), z(0.0), chronic(0.0) {}

    void println(File& file) {
      file.print("T: ");
      file.print(chronic);
      file.print(" x: ");
      file.print(x);
      file.print(" y: ");
      file.print(y);
      file.print(" z: ");
      file.println(z);
    }
};

class Printer{
  public:
    cartesianer data;
    char type;

    Printer(): data(), type(0) {}
    Printer(const cartesianer& cartesianObj, char charValue)
        : data(cartesianObj), type(charValue) {}

    void println(File& file){
      switch (type)
      {
      case 1:
        file.print("Racc: ");
        break;
      case 2:
        file.print("Rvel: ");
        break;
      case 3:
        file.print("Rpos: ");
        break;
      case 4:
        file.print("Kacc: ");
        break;
      case 5:
        file.print("Kpos: ");
        break;
      
      default:
        file.print("Unk: ");
        break;
      }

      data.println(file);
    }
};

Printer buffer[BUFFER_SIZE];

template<class Xena> 
struct NodeFuux{
  Xena data;
  NodeFuux<Xena> *next;
};

template <class Xena>
class LinkedListFuux{
  public:
    NodeFuux<Xena> *head;
    int size = 0;
    char type;

    LinkedListFuux(): head(NULL) {};
    LinkedListFuux(char typegiven): head(NULL), type(typegiven) {}

    ~LinkedListFuux(){
      while(!empty()){
        deleterLLF();
      }
    }
    bool empty() const{return head == NULL;}

    bool emptysqr() const{
      return head->next == NULL;
    }

    void setType(char input){ 
      type = input;
      return;
    }


    void insert(Xena &givenData) {
      NodeFuux<Xena> *Behemoth = new NodeFuux<Xena>;
      Behemoth->data = givenData;
      Behemoth->next = head;
      head = Behemoth;
      size++;
    }

    void deleterLLF(){
      NodeFuux<Xena> *arnolder = head;
      head = arnolder->next;
      delete arnolder;
      size--;
    }

    void clean(){
      if(size < 10){ return; }
      NodeFuux<Xena> *arnolder = head;
      NodeFuux<Xena> *sandpaper;
      for(int n = 0; n < 5 && arnolder != NULL; n++){
        arnolder = arnolder->next;
      }


      if (arnolder == NULL || arnolder->next == NULL) {
        return;
      }


      NodeFuux<Xena> *Behelit = arnolder;
      while (Behelit->next != NULL) {
        sandpaper = Behelit->next;
        Printer Shalltear(sandpaper->data, type);

        xSemaphoreTake(emptysema, portMAX_DELAY);
        xSemaphoreTake(mutex, portMAX_DELAY);

        buffer[in] = Shalltear;
        in = (in+1) % BUFFER_SIZE;
        count++;

        xSemaphoreGive(mutex);
        xSemaphoreGive(full);

        Behelit->next = sandpaper->next;
        delete sandpaper;
        size--;
      }
    }

};


void KPredProcessCovarNGain(){
  stdDevBNOPosx += stdDevBNOVelx;
  stdDevBNOPosy += stdDevBNOVely;
  stdDevBNOPosz += stdDevBNOVelz;
  KGainx[0] = stdDevBNOPosx/(stdDevBNOPosx + (AvgErrorPosX * AvgErrorPosX));
  KGainx[1] = stdDevBNOVelx/(stdDevBNOVelx + (AvgErrorVelX * AvgErrorVelX)); 
  KGainy[0] = stdDevBNOPosy/(stdDevBNOPosy + (AvgErrorPosY * AvgErrorPosY));
  KGainy[1] = stdDevBNOVely/(stdDevBNOVely + (AvgErrorVelY * AvgErrorVelY));
  KGainz[0] = stdDevBNOPosz/(stdDevBNOPosz + (AvgErrorPosZ * AvgErrorPosZ));
  KGainz[1] = stdDevBNOVelz/(stdDevBNOVelz + (AvgErrorVelZ * AvgErrorVelZ)); 
}

LinkedListFuux<cartesianer> accel_vals {1};
LinkedListFuux<cartesianer> velocity_vals{2};
LinkedListFuux<cartesianer> position_vals{3};

LinkedListFuux<cartesianer> Kvel{4};
LinkedListFuux<cartesianer> Kpos{5};

Adafruit_BNO055 bno = Adafruit_BNO055(-1, 0x28, &Wire); 

void appendFile(fs::FS &fs, String path, NodeFuux<cartesianer> *input_head[]){

    File file = fs.open(path, FILE_APPEND);
    if(!file){
        Serial.println("Failed to open file for appending");
        return;
    }

    String prefixes[5]= {"Racc ", "Rvel ", "Rpos ", "Kvel ", "Kpos "};

    for (int i =0; i <5; i++){
        if (input_head[i]) {
            file.print(position_vals.size);
            file.print(" ");
            file.print(prefixes[i]);
            input_head[i]->data.println(file);
        }
    }

    file.close();
}


void* producer(void* arg){

  unsigned long threadender = micros();

  while((micros() - threadender) < 60000000){
    
    delay(BNO055_SAMPLERATE_DELAY_MS); 
    sensors_event_t linearAccelData;
    bno.getEvent(&linearAccelData, Adafruit_BNO055::VECTOR_LINEARACCEL);

    cartesianer kikai;
    unsigned long Chronos = micros();
    kikai.chronic = (float)((float(Chronos) / 1000000) - (starttimefloated/1000000));
    imu::Quaternion quat = bno.getQuat();

    double rm[3][3];

    rm[0][0] = quat.w()*quat.w() + quat.x()*quat.x() - quat.y()*quat.y() - quat.z()*quat.z();   
    rm[0][1] = 2*quat.x()*quat.y() - 2*quat.w()*quat.z();            
    rm[0][2] = 2*quat.x()*quat.z() + 2*quat.w()*quat.y();
    rm[1][0] = 2*quat.x()*quat.y() + 2*quat.w()*quat.z();       
    rm[1][1] = quat.w()*quat.w() - quat.x()*quat.x() + quat.y()*quat.y() - quat.z()*quat.z();          
    rm[1][2] = 2*quat.y()*quat.z() - 2*quat.w()*quat.x();     
    rm[2][0] = 2*quat.x()*quat.z() - 2*quat.w()*quat.y();       
    rm[2][1] = 2*quat.y()*quat.z() + 2*quat.w()*quat.x();            
    rm[2][2] = quat.w()*quat.w() - quat.x()*quat.x() - quat.y()*quat.y() + quat.z()*quat.z();

    float globalAccelerationX = (rm[0][0] * linearAccelData.acceleration.x + rm[0][1] * linearAccelData.acceleration.y + rm[0][2] * linearAccelData.acceleration.z) ;
    float globalAccelerationY = (rm[1][0] * linearAccelData.acceleration.x + rm[1][1] * linearAccelData.acceleration.y + rm[1][2] * linearAccelData.acceleration.z) ;
    float globalAccelerationZ = (rm[2][0] * linearAccelData.acceleration.x + rm[2][1] * linearAccelData.acceleration.y + rm[2][2] * linearAccelData.acceleration.z) ;


    if (globalAccelerationX <  0.16 && globalAccelerationX > -0.16){
      globalAccelerationX =0;
    }
    if (globalAccelerationY <  0.16 && globalAccelerationY > -0.16){
      globalAccelerationY =0;
    }
    if (globalAccelerationZ <  0.16 && globalAccelerationZ > -0.16){
      globalAccelerationZ =0;
    }

    kikai.x = globalAccelerationX;
    kikai.y = globalAccelerationY;
    kikai.z = globalAccelerationZ;

    accel_vals.insert(kikai);

    cartesianer BromineDioxide;
    cartesianer Bromo;

    if(accel_vals.empty()){
      ;
    } else if (accel_vals.emptysqr()){
      BromineDioxide.chronic = accel_vals.head->data.chronic;
      BromineDioxide.x = (1.0f/2)*(accel_vals.head->data.chronic)*(accel_vals.head->data.x);
      BromineDioxide.y = (1.0f/2)*(accel_vals.head->data.chronic)*(accel_vals.head->data.y);
      BromineDioxide.z = (1.0f/2)*(accel_vals.head->data.chronic)*(accel_vals.head->data.z);
      velocity_vals.insert(BromineDioxide);
    } else{
    Bromo.chronic= accel_vals.head->data.chronic;
    Bromo.x= (1.0f/2)*(accel_vals.head->data.chronic - accel_vals.head->next->data.chronic)*(accel_vals.head->data.x + accel_vals.head->next->data.x);
    Bromo.y= (1.0f/2)*(accel_vals.head->data.chronic - accel_vals.head->next->data.chronic)*(accel_vals.head->data.y + accel_vals.head->next->data.y);
    Bromo.z= (1.0f/2)*(accel_vals.head->data.chronic - accel_vals.head->next->data.chronic)*(accel_vals.head->data.z + accel_vals.head->next->data.z);
    velocity_vals.insert(Bromo);
    }


    if(velocity_vals.empty()){
      ;
    } else if (velocity_vals.emptysqr()){
      BromineDioxide.chronic = velocity_vals.head->data.chronic;
      BromineDioxide.x = (1.0f/2)*(velocity_vals.head->data.chronic)*(velocity_vals.head->data.x);
      BromineDioxide.y = (1.0f/2)*(velocity_vals.head->data.chronic)*(velocity_vals.head->data.y);
      BromineDioxide.z = (1.0f/2)*(velocity_vals.head->data.chronic)*(velocity_vals.head->data.z);
      position_vals.insert(BromineDioxide);
    } else{
    Bromo.chronic= velocity_vals.head->data.chronic;
    Bromo.x= (1.0f/2)*(velocity_vals.head->data.chronic - velocity_vals.head->next->data.chronic)*(velocity_vals.head->data.x + velocity_vals.head->next->data.x);
    Bromo.y= (1.0f/2)*(velocity_vals.head->data.chronic - velocity_vals.head->next->data.chronic)*(velocity_vals.head->data.y + velocity_vals.head->next->data.y);
    Bromo.z= (1.0f/2)*(velocity_vals.head->data.chronic - velocity_vals.head->next->data.chronic)*(velocity_vals.head->data.z + velocity_vals.head->next->data.z);
    position_vals.insert(Bromo);
    }

    cartesianer painful;
    cartesianer messiah;
    painful.chronic= accel_vals.head->data.chronic;
    messiah.chronic= painful.chronic;
    float timediff = 0.01;
    if(accel_vals.empty()){
      ;
    }else if (accel_vals.emptysqr()){
      timediff = accel_vals.head->data.chronic;
    }else{
      timediff = accel_vals.head->data.chronic - accel_vals.head->next->data.chronic;
    }
    cartesianer previousState;
    cartesianer previousVelocity;
    if(Kpos.empty()){
      previousState.x=0;
      previousState.y=0;
      previousState.z=0;
    }else{
      previousState.x = Kpos.head->data.x;
      previousState.y = Kpos.head->data.y;
      previousState.z = Kpos.head->data.z;
    }
    if(Kvel.empty()){
      previousVelocity.x=0;
      previousVelocity.y=0;
      previousState.z=0;
    }else{
      previousVelocity.x=Kvel.head->data.x;
      previousVelocity.y=Kvel.head->data.y;
      previousVelocity.z=Kvel.head->data.z;
    }

    painful.x = previousState.x + (previousVelocity.x * timediff) + ((1.0f/2) * timediff * timediff * accel_vals.head->data.x);
    messiah.x = previousVelocity.x + (accel_vals.head->data.x * timediff);
    painful.y = previousState.y + (previousVelocity.y * timediff) + ((1.0f/2) * timediff * timediff * accel_vals.head->data.y);
    messiah.y = previousVelocity.y + (accel_vals.head->data.y * timediff);
    painful.z = previousState.z + (previousVelocity.z * timediff) + ((1.0f/2) * timediff * timediff * accel_vals.head->data.z);
    messiah.z = previousVelocity.z + (accel_vals.head->data.z * timediff);

    KPredProcessCovarNGain();

    painful.x = painful.x + (KGainx[0] * (position_vals.head->data.x - painful.x));
    messiah.x = messiah.x + (KGainx[1] * (velocity_vals.head->data.x - messiah.x));
    painful.y = painful.y + (KGainy[0] * (position_vals.head->data.y - painful.y));
    messiah.y = messiah.y + (KGainy[1] * (velocity_vals.head->data.y - messiah.y));
    painful.z = painful.z + (KGainz[0] * (position_vals.head->data.z - painful.z));
    messiah.z = messiah.z + (KGainz[1] * (velocity_vals.head->data.z - messiah.z));

    Kpos.insert(painful);
    Kvel.insert(messiah);

    
    accel_vals.clean();
    velocity_vals.clean();
    position_vals.clean();
    Kvel.clean();
    Kpos.clean();  
  }
  xSemaphoreTake(emptysema, portMAX_DELAY);
  xSemaphoreTake(mutex, portMAX_DELAY);
  cartesianer ender;
  ender.x = 10000000;
  ender.y = 10000000;
  ender.z = 10000000;
  ender.chronic = 0;
  Printer terminator(ender, 40);
  buffer[in] = terminator;
  xSemaphoreGive(mutex);
  xSemaphoreGive(full);
  
  pthread_exit(NULL);
}

void* consumer(void* arg){
  unsigned long threadender = micros();
  cartesianer ender;
  ender.x = 10000000;
  ender.y = 10000000;
  ender.z = 10000000;
  ender.chronic = 0;
  Printer terminator(ender, 40);

  fs::FS fs = SD;

  File file = fs.open(LoggerFilename, FILE_APPEND);
  if (!file)
  

  while((micros() - threadender) < 60000000){
        xSemaphoreTake(full, portMAX_DELAY);
        xSemaphoreTake(mutex, portMAX_DELAY);

        Printer input = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;

        xSemaphoreGive(mutex);
        xSemaphoreGive(emptysema);

        if (input.type == terminator.type) {
          if(input.data.x == ender.x && input.data.y == ender.y && input.data.z == ender.z){ break;}
        }

        input.println(file);
  }

  file.close();
  pthread_exit(NULL);
}








void setup() {
  Serial.begin(115200);

  emptysema = xSemaphoreCreateCounting(BUFFER_SIZE, BUFFER_SIZE);
  full = xSemaphoreCreateCounting(BUFFER_SIZE, 0);
  mutex = xSemaphoreCreateMutex();

  
  if(!bno.begin())
  {
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  delay(1000);
  
  bno.setExtCrystalUse(true);

  
  #ifdef REASSIGN_PINS
    SPI.begin(sck, miso, mosi, cs);
  #endif
  
  if(!SD.begin()){ 
    Serial.println("SD CARD MODULE FAILED. CHECK FUUX DIAGRAM, CHECK SD CONNECTION.");
  }

  starttime = micros();
  uint8_t Calib= 31;
  uint8_t system, gyro, accel, mag = 0;

  while (Calib){
    bno.getCalibration(&system, &gyro, &accel, &mag);
    if(system == 3 && gyro == 3 && accel == 3 && mag == 3){
      Calib = 0;
    } else if ((micros() - starttime) > 60000000){
      Calib = 0;
    }
    delay(BNO055_SAMPLERATE_DELAY_MS);
  }

  delay(30000);

  starttime = micros();
  starttimefloated = float(starttime);

  pthread_t prodThread, conThread;

  while((micros() - starttime) < 180000000){

    if(pthread_create(&prodThread, NULL, producer, NULL) != 0){
      Serial.println("ERROR CREATING PRODUCER THREAD");
      while(1){}
    }
    if(pthread_create(&conThread, NULL, consumer, NULL) != 0){
      Serial.println("ERROR CREATING CONSUMER THREAD");
      while(1){}
    }

    pthread_join(prodThread, NULL);
    pthread_join(conThread, NULL);

  }

  vSemaphoreDelete(emptysema);
  vSemaphoreDelete(full);
  vSemaphoreDelete(mutex);

}

void loop() {

}