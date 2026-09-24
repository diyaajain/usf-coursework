/* Name: Diya Jain U81673988 */ 
/* This is the first question of the Project 5 */
/* Made the program to see if a number is divisble by 11 or not */
#include <stdio.h>
#include <string.h>

int divisble(char num[]); 

int divisble(char num[])
{
    int n=0;
    /* n = sizeof(num)/sizeof(num[0]); */
    n = strlen(num);
    long odd_sum = 0;
    long even_sum = 0;
    int i;
    int divider = 0;
    for(i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            odd_sum += num[i] - '0'; /* taking sum of odd places */
        } 
        else 
        {
            even_sum += num[i] - '0';/* taking sum of even places */
        }
    }
    divider = odd_sum - even_sum; /* calculates the diffrence between the odd and even sum */
    if (divider % 11 == 0 )
    {
        num[0] = 'y';
    }

return 0;
}

int main()
{
    char num[1000] = {'\0'}; 
    char num1[1000] = {'\0'};

    printf("Enter the value of X: ");
    scanf("%s", num);

    /*printf("%s \n", num); check point*/
    
    strcpy(num1, num); /* made the copy of the string */

    divisble(num); /* made a function to see if it is divisble by 11 or not */

    if (num[0] == 'y') 
    {
        printf("%s is a multiple of 11\n", num1);
    }
    else
    {
        printf("%s is not a multiple of 11\n", num1);
    } 

return 0;
}