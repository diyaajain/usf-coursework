/* Name: Diya Jain U81673988 */ 
/* This is my program for the second question of Project 2. */
/* In this program I have checked to see if the word is in alphabetical order or not. */
#include <stdio.h>
#include <ctype.h>
int main()
{
    char a;
    char b;
    int flag = 1;
    printf("Enter input: ");
    a = getchar(); 
    /* changes the character to lowercase */
    a = tolower(a); 
    /* loop will run till white space is reached */
    while ((b=getchar()) != '\n')             
    {
        b = tolower(b);
        /* this loop will determine if the word is alphabetical or not. */
        if((a>='a' && a<='z') && (b>='a' && b<='z'))
        {
            /* if it is not alphabetical the flag will turn to 0. */
            if (a>b){ 
                flag = 0;
            }
        }
        /* this loop will run if they characters are not alphabets. */
        else{ 
            flag = 0;
        }
        a=b;
    }
    if (flag == 1){
        printf("Output: In order \n");
    }  
    else{
    printf("Output: Not in order \n");
    }
    return 0;
}