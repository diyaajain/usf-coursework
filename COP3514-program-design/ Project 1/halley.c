/* Name: Diya Jain U81673988 */ 
/* This is my program for the second question of Project 1. */
/* In this program I have calculated the next apperance of Halley's comet based on the user's input. */
#include <stdio.h>
int main(){
    int user_year;
    int next_year;
    int last_app;
    printf("Enter year: "); /* Asking the user for input. */
    scanf("%d", &user_year);
    if (user_year>=0 && user_year<=1986){ /* This block will execute if the entered year is below 1986. */
        printf("Invalid year %.1d \n", user_year);
        printf("Input year must be greater than 1986 \n"); /* Tells the user that the year must be greater than 1986. */
    }
    else{ /* This block will run for all the other cases. */
    last_app = ((user_year-1986)/76)*76+1986; /* This is the formula that I have used to find the last appearance. */
    next_year = (last_app + 76); /* This line just adds 76 to the  last appearance. */
    printf("Next Apperance: %.1d\n", next_year); 
    }
    return 0;
}