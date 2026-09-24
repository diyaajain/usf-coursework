/* Name: Diya Jain U81673988 */ 
/* This is my program for the second question of Project 3. */
/* In this program I have found the factorial off all the numbers mentioned in the array.  */
#include <stdio.h>
void calculate_fact(int [], int n , int []); /* declartion of the void function.*/

int fact(int n) /* recursive function for finding factorial.*/
    {
        if (n <= 1) 
            return 1;
        
        else 
            return n * fact(n - 1); /* finding factorial */
    }

void calculate_fact(int a[], int n , int b[]) 
{
    int i,j;
    for(i = 0; i <n; i++) 
        {
            b[i]=fact(a[i]); /* calling the recursion function to find factorial.*/
        }
    for(j = 0; j <n; j++)
        {
            printf("%d ", b[j]); /* printing the numbers in the array b.*/
        }
}

int main()
{   

    int length;
    printf("Enter the length of the input array: ");
    scanf("%d", &length);
    const int len_array= length;
    int b[len_array];
    int ele_array[len_array];
    int i;
    int n;
    
    if(len_array<0) /* if loop is wrong or invalid.*/
    {
      printf("Factorial is not defined for negative numbers.");
    }
    if(len_array>0)
    {
        printf("Enter the array elements: "); /* entering the array elements.*/
        for(i = 0; i < len_array; i++)
        {
            scanf("%d", &ele_array[i]);
        }
    }
    
    calculate_fact(ele_array,len_array, b); /* calling the void */
    return 0;
}