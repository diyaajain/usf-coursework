/* Name: Diya Jain U81673988 */ 
/* This is my program for the second question of Project 2. */
/* In this program I have checked to see if the word is in alphabetical order or not. */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int in_order(char *word);

int in_order(char *word) /* made the function */
{
    int p = 1;
    *word = tolower(*word);
    while(word[p] != '\0') 
    {
        if((word[p]) > (word[p-1]))
        {
            return 1;                
        }
        p++;
    }

    return 0;
}

int main(int argc, char *argv[])
{   
    if (argc >2 || argc == 1) /* displays if wrong number of sruguments are entered*/
    {
        printf("Incorrect number of arguments. Usage: ./a.out word \n");
        return 1;
    }
    char *word = argv[1];
    if (in_order(word) == 1)
    {
        printf("In order\n");
    }
    else 
    {
        printf("Not in order\n");
    }
    return 0;
}