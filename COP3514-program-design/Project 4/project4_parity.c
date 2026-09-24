/* Name: Diya Jain U81673988*/
/* This programs tells us if the array entred has an even parity or odd parity. */
/* If the program is neither odd nor even it will tells us that the array is not good. */

#include<stdio.h>
void find_parity(int *a, int n, int *all_even, int *all_odd); 
int main()
{
    int n;
    int even=0;
    int odd=0;
    int i;
    printf("Enter the length of the input array: "); /* asking input of length */
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: "); /* asking the numbers of the array */
    for (i = 0; i<n; i++)
    {
    scanf("%d", &arr[i]);
    }

    find_parity(arr,n, &even, &odd); /* calling the specific funtion to find the array' parity */ 
 
    /* According to the caluculation above it will run through all the test cases to see if the array is even, odd or not good */

    if (even == 1 && odd == 0 )
    {
        printf("Output: good, all elements are even \n");
    }
    if (even == 0 && odd == 1)
    {
        printf("Output: good, all lements are odd \n");
    }
    if (even == 1 && odd == 1)
    {
        printf("Output: not good \n");
    }
return 0;
}
void find_parity(int *a, int n, int *all_even, int *all_odd) /* the function that finds the parity of the array */
{
    int *p;   
    for (p = a; p < a+n; p++) /* using pointer arithemtic to check all the elements in the array */
    {
        if((*p % 2) == 0) /* when the number is divided by 2 and the remainder is 2, the number is even */
        {   
            *all_even = 1;
        }
        if ((*p % 2) != 0) /* if the remainder is not 0, the number is odd */
        {
            *all_odd = 1;
        }
    }
}