/* Name: Diya Jain U81673988 */ 
/* This is my program for the first question of Project 2. */
/* In this program I have calculated the calculated the cost the items bought at a grocery market. */

#include <stdio.h>
int main()
{
    int item_price; /* Intialization of the variables used the program. */
    int units;
    int mon_amount;
    int dif;
    int i;
    int mon_2pay = 0;
    printf("Enter item price: ");
    scanf("%d", &item_price);
    if(item_price<=0){ /* This block will run if the item price entered is less than or equal to zero. */
        printf("Invalid item price %d \n",item_price);
        printf("Item price should be greater than 0.");
        return 1;
    }
    printf("Enter number of units: ");
    scanf("%d", &units);
    if (units <=0 ){ /* This block will execute if the units entered is below zero. */
        printf("Invalid number of units %d \n",units);
        printf("Number of units should be greater than 0.");
        return 1;
    }
    printf("Enter money amount: ");
    scanf("%d", &mon_amount);
    if (mon_amount<0){ /* This will execute if the money entered is below zero. */
        printf("Invalid money amount %d\n",mon_amount);
        printf("Money amount must be greater than or equal to 0");
        return 1;
    }
    if (units >=1){ /* This block will execute if all the values are good. */
        for(i=0; i<=units ; i++){ /* This block will help in finding the total money that is to be paid. */
            mon_2pay = mon_2pay + (item_price*i); /* The formula used for finding the total amount. */
        }
        dif = mon_2pay - mon_amount; /* This is the difference between the total amount to be paid and the money entered by user. */
    if (dif<=0) { /* If difference is less than 0, then the customer has enought money. */
        printf("Has enough money.");
    }
    else if (dif<= mon_2pay ){ /* This block will tell the extra money which is needed to fulfill the purchase. */
        printf("Needs %d dollar(s) to complete the purchase!", dif);
    }
    }

return 0;
}