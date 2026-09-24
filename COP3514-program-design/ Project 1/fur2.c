/* Name: Diya Jain U81673988 */ 
/* This is my program for the first question of Project 1. */
/* In this program I have calculated the rent of each furniture in the list based on the months rented. */
#include <stdio.h>
int main()
{
    int furniture; /* initialized the variables for the program. */
    int months;
    int rent;
    int year;
    int rem_months;
    printf("Please select from the following menu: \n");
    printf("1. Sofa, 2. Loveseat, 3. 4 Post Bed, 4. Dresser, 5. Kitchen Table\n");
    printf("Enter Furiture Selection: ");
    scanf("%d", &furniture); /* asked the user for the furniture input. */
    /* used if statement which helped me to go in the specific if block of the furniture. */
    if (furniture<1){ /* This if statement will run only if the furniture selection is wrong. */
        printf("Invalid input. The input should be in the range of 1 to 5.\n");
    }
    if (furniture>5){ /* This if statement will run only if the furniture selection is wrong. */
        printf("Invalid input. The input should be in the range of 1 to 5.\n");
    }
    if (furniture == 1){ /* This if statement will run only if the furniture selction is 1. */
        printf("Enter months rented: ");
        scanf("%d", &months);
        if (months < 1) /* Asking the user for months again if they entered the wrong number. */
        {
            printf("Invalid input. Enter a positive number for months rented.\n");
            scanf("%d", &months);
        }
        else if (months>=1 && months<=12) /* if months entered is between 1 to 12. This will tell them the desired amount. */
        {
            rent = (60 + (months-1)*45);
            if (rent>=450){ /* This block will execute only if the rent is above the total amount allowed for a year. */
                printf("Amount due ($) = 450");
            }
            if (rent<=450){ /* This block will execute if the amount is below to maximum allowed limit. */
                printf("Amount due ($) = %d\n",rent);
            }
        }
        else /* This block will execute only if the the number of entered of months entered is greater than 12. */
        {
            /* In this block, I first found the total number of years that would make a year. The quotient is the number of years. */
            /* Then I foundd the number of months that would be left from made up years. The remainder gives us the number of months. */
            /* From those years and months I found the rent that is supposed to be paid. */
            year = months/12; /* made up years */
            rem_months = months%12; /* finding the remaining months */
            rent = 450*year + 45*rem_months; /* finding the rent */
            printf("Amount due ($) = %d\n",rent);
        }
    }
    if (furniture == 2){ /* This if statement will run only if the furniture selction is 2. */
        printf("Enter months rented: "); /* Asking the user for the months rented. */
        scanf("%d", &months);
        if (months < 1) /* Asking the user for months again if they entered the wrong number. */
        {
            printf("Invalid input. Enter a positive number for months rented.\n");
            scanf("%d", &months);
        }
        else if (months>=1 && months<=12) /* if months entered is between 1 to 12. This will tell them the desired amount. */
        {
            rent = (45 + (months-1)*30);
            if (rent>=280){ /* This block will execute only if the rent is above the total amount allowed for a year. */
                printf("Amount due ($) = 280");
            }
            if (rent<=280){ /* This block will execute if the amount is below to maximum allowed limit. */
                printf("Amount due ($) = %d\n",rent);
            }
        }
        else /* This block will execute only if the the number of entered of months entered is greater than 12. */
        {
            /* In this block, I first found the total number of years that would make a year. The quotient is the number of years. */
            /* Then I foundd the number of months that would be left from made up years. The remainder gives us the number of months. */
            /* From those years and months I found the rent that is supposed to be paid. */
            year = months/12; /* made up years */
            rem_months = months%12; /* finding the remaining months */
            rent = 280 * year + 30*rem_months; /* finding the rent */
            printf("Amount due ($) = %d\n",rent);
        }
    }
    if (furniture == 3){ /* This if statement will run only if the furniture selction is 3. */
        printf("Enter months rented: ");
        scanf("%d", &months);
        if (months < 1) /* Asking the user for months again if they entered the wrong number. */
        {
            printf("Invalid input. Enter a positive number for months rented.\n");
            scanf("%d", &months);
        }
        else if (months>=1 && months<=12) /* if months entered is between 1 to 12. This will tell them the desired amount. */
        {
            rent = (55 + (months-1)*38);
            if (rent>=350){ /* This block will execute only if the rent is above the total amount allowed for a year. */
                printf("Amount due ($) = 350");
            }
            if (rent<=350){ /* This block will execute if the amount is below to maximum allowed limit. */
                printf("Amount due ($) = %d\n",rent);
            }
        }
        else /* This block will execute only if the the number of entered of months entered is greater than 12. */
        {
            /* In this block, I first found the total number of years that would make a year. The quotient is the number of years. */
            /* Then I foundd the number of months that would be left from made up years. The remainder gives us the number of months. */
            /* From those years and months I found the rent that is supposed to be paid. */
            year = months/12; /* made up years */
            rem_months = months%12; /* finding the remaining months */
            rent = 350 * year + 38*rem_months; /* finding the rent */
            printf("Amount due ($) = %d\n",rent);
        }
    }
    if (furniture == 4){ /* This if statement will run only if the furniture selction is 4. */
        printf("Enter months rented: ");
        scanf("%d", &months);
        if (months < 1) /* Asking the user for months again if they entered the wrong number. */
        {
            printf("Invalid input. Enter a positive number for months rented.\n");
            scanf("%d", &months);
        }
        else if (months>=1 && months<=12) /* if months entered is between 1 to 12. This will tell them the desired amount. */
        {
            rent = 28 +((months-1)*25);
            if (rent>=200){ /* This block will execute only if the rent is above the total amount allowed for a year. */
                printf("Amount due ($) = 200");
            }
            if (rent<=200){ /* This block will execute if the amount is below to maximum allowed limit. */
                printf("Amount due ($) = %d\n",rent);
            }
        }
        else /* This block will execute only if the the number of entered of months entered is greater than 12. */
        {
            /* In this block, I first found the total number of years that would make a year. The quotient is the number of years */
            /* Then I foundd the number of months that would be left from made up years. The remainder gives us the number of months. */
            /* From those years and months I found the rent that is supposed to be paid. */
            year = months/12; /* made up years */
            rem_months = months%12;/* finding the remaining months */
            rent = 200 * year + 25*rem_months; /* finding the rent */
            printf("Amount due ($) = %d\n",rent);
        }
    }
    if (furniture == 5){ /* This if statement will run only if the furniture selction is 5. */
        printf("Enter months rented: ");
        scanf("%d", &months);
        if (months < 1) /* Asking the user for months again if they entered the wrong number. */
        {
            printf("Invalid input. Enter a positive number for months rented.\n");
            scanf("%d", &months);
        }
        else if (months>=1 && months<=12) /* if months entered is between 1 to 12. This will tell them the desired amount. */
        {
            rent = (35 + (months-1)*20);
            if (rent>=220){ /*  This block will execute only if the rent is above the total amount allowed for a year. */
                printf("Amount due ($) = 220");
            }
            if (rent<=220){ /* This block will execute if the amount is below to maximum allowed limit. */
                printf("Amount due ($) = %d\n",rent);
            }
        }
        else /* This block will execute only if the the number of entered of months entered is greater than 12. */
        {
            /* In this block, I first found the total number of years that would make a year. The quotient is the number of years. */
            /* Then I foundd the number of months that would be left from made up years. The remainder gives us the number of months. */
            /* From those years and months I found the rent that is supposed to be paid. */
            year = months/12; /* made up years */
            rem_months = months%12; /* finding the remaining months */
            rent = 220 * year + 20*rem_months;
            printf("Amount due ($ ) = %d\n",rent);
        }
    }
    printf("\n");
    return 0;
}