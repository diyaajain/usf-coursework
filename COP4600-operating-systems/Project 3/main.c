// Name: Diya Jain
// U81673988
// Project 3: Bounded Buffer

#define _REENTRANT
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>

// SET BUFFER SIZE
#define BUFFERSIZE 15

int count = 0;  // Character counter
int i = 0;       // Index of producer
int j = 0;       // Index of consumer
char buffer[BUFFERSIZE]; // Buffer

// SEMAPHORES
sem_t *buffer_full;
sem_t *buffer_empty;
sem_t *mutex;

// PRODUCER FUNCTION
void *producer() {
    // Prepare for file Input
    char newChar;
    FILE *fp;
    fp = fopen("mytest.dat", "r");
    while (1) {
        sem_wait(buffer_empty); // Wait if buffer is full
        sem_wait(mutex);        // Acquire the mutex

        // Loop continuously until the end of the file
        if (fscanf(fp, "%c", &newChar) != EOF) {
            buffer[i] = newChar;
            i = (i + 1) % BUFFERSIZE;
        } else {
            // Place an asterisk in the buffer when the end of file is reached
            buffer[i] = '*';
            // Release the buffer
            sem_post(mutex);
            sem_post(buffer_full);
            break;
        }

        sem_post(mutex);        // Release the mutex
        sem_post(buffer_full);  // Signal that buffer is no longer empty
    }
    fclose(fp);
    return NULL;
}

// CONSUMER FUNCTION
void *consumer() {
    while (1) {
        sleep(1); // Delay for the consumer
        sem_wait(buffer_full); // Wait if buffer is empty
        sem_wait(mutex);       // Acquire the mutex
        fflush(stdout);        // Flush the output

        // Loop continuously until an asterisk is found in the buffer
        if (buffer[j] != '*') {
            printf("%c", buffer[j]);
            j = (j + 1) % BUFFERSIZE;
            if (buffer[j] != '\n')
                count = count + 1; // Newlines not considered as characters
        } else {
            sem_post(mutex);       // Release the mutex
            sem_post(buffer_empty); // Signal that buffer is no longer full
            exit(0);
        }

        sem_post(mutex);       // Release the mutex
        sem_post(buffer_empty); // Signal that buffer is no longer full
    }
    return NULL;
}

int main() {
    pthread_t tid1[1];      // Process id for thread 1
    pthread_t tid2[1];      // Process id for thread 2
    pthread_attr_t attr[1]; // Attribute pointer array

    // Create and initialize semaphores
    buffer_full = sem_open("/buffer_full", O_CREAT, 0666, 0);
    buffer_empty = sem_open("/buffer_empty", O_CREAT, 0666, BUFFERSIZE);
    mutex = sem_open("/mutex", O_CREAT, 0666, 1);

    if (buffer_full == NULL || buffer_empty == NULL || mutex == NULL) {
        printf("Error creating semaphores\n");
        exit(1);
    }

    fflush(stdout);

    // Required to schedule thread independently.
    pthread_attr_init(&attr[0]);
    pthread_attr_setscope(&attr[0], PTHREAD_SCOPE_SYSTEM);
    // End to schedule thread independently

    // Create the threads
    pthread_create(&tid1[0], &attr[0], producer, NULL);
    pthread_create(&tid2[0], &attr[0], consumer, NULL);

    // Wait for the threads to finish
    pthread_join(tid1[0], NULL);
    pthread_join(tid2[0], NULL);

    // Destroy semaphores
    sem_close(buffer_full);
    sem_close(buffer_empty);
    sem_close(mutex);

    printf("\n------------------------------------------------\n");
    printf("From parent counter  =  %d\n", count);
    printf("------------------------------------------------\n");
    printf("\t\t    End of simulation\n");

    exit(0);
}