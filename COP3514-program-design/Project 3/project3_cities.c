/* Name: Diya Jain U81673988 */
/* This is my program for the first question of Project 3. */
/* In this program I have found the cities that can travveled by a drone.  */
#include <stdio.h>
int main(){
    int cities;
    int num_drones;
    int i_city, distance;
    int i=0;
    int flag=1;
    printf("Enter number of cities (N): "); /* Asking for input */
    scanf("%d", &cities);
    if (cities<=0 || cities>100){
        printf("Invalid number of cities %d \n", cities); /* invalid input*/
        printf("Must be in the range [1,100] \n");
        return 1;
    }
    printf("Enter number of drones (M): ");
    scanf("%d", &num_drones); /* scanning for input of drones*/
    if (num_drones<0 || num_drones>100){
        printf("Invalid number of drones %d \n", num_drones);
        printf("Must be in the range [1,100] \n");
    }
    if (cities>=1 && cities<=100 && num_drones>=1 && num_drones<=100){
        printf("Enter drone list: \n");
        for (i=0; i<num_drones; i++);
        scanf ("%d%d \n", &i_city, &distance);
        if (i_city>=1 && i_city<=cities && distance>=1 && distance<=cities){ /* finding the distance travveled by a drone*/
            int c_initial[]={i_city};
            int d_initial[]={distance};
            for (i=0; i<cities; i++)
            {
                int temp = c_initial[i]%d_initial[i];
                if (temp==1){
                    temp = temp + d_initial[0];
                }
            }
        }
    }
        if (flag==0){
        printf("Invalid input");
    }
    else{
        printf("Cities reached by drone: \n"); /* prinitng the cities reached by the drone.*/
        printf("could not do it.");
    }
    return 0;
}