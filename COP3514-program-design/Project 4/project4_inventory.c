/* Name: Diya Jain U81673988*/
/* This programs tells us how many computers can be made by the entered number of parts and part types. */

#include <stdio.h>

int find_minimum(int *a, int n); 

int main(){
    int N;
    int K;
    int i,j;
    int freq[10000]={0};
    int count;
    printf("Enter number of parts (N): "); /* asks the user for the number of parts */
    scanf("%d", &N);
    if (N<1 || N>1000000){
        printf("Invalid number of parts %d \n", N);
        printf("Must be in the range [1,1000000] \n");
        return 1;
    }
    printf("Enter number of part types (K): "); /* asks the user for the part type */
    scanf("%d", &K);
    if (K<1 || K>10000){
        printf("Invalid number of part types %d \n", K);
        printf("Must be in the range [1,10000]\n");
        return 1;
    }
    
    int part_list[N];
    printf("Enter part list: \n"); /* asks the user to enter the part list */
    for (i = 0; i<N; i++)
        {
            scanf("%d", &part_list[i]);
            if(part_list[i]<=0 || part_list[i]>K)
            {
                printf("Invalid list of parts \n");
                printf("Part codes must be in the range [1,%d]\n", K);
                return 1;
            }
        }
        
        
    for (i=0; i<N; i++) /* this for loops finds the total number of occurences of the element in the array i.e frequency */
        {   
            count=0;
            
            for (j=0; j<N;j++)
            {
                if (part_list[i] == part_list[j])
                    {
                        count+=1;
                    }
                else 
                {
                    continue;
                }
            }
            freq[i]= count;
        }
    printf("The factory can build %d computer(s)",find_minimum (freq,N)); /* prints the total number of computers that can be built */
        
    return 0; 
}

/* Finds the minimum value in the frequency array */

int find_minimum(int *a, int n) \
{
    int *p;  
    int *minimum;
    minimum = a;

    for (p = a ; p < a+n; p++)
    {
        if (*p <= *minimum)
        {
            *minimum = *p;
        }
        else
        {
            continue;
        }
    }
    return *minimum; /* Return the value which is minimum in the array */
}