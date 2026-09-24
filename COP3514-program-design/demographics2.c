/* Name: Diya Jain U81673988 */
/* This program sort the states by percentage of population whose ages are equal or greater than 65 years old */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct state  /* made the structure for the state with the following fields */
{
    char state_name[150];
    int population_2020;
    int population_2010;
    double ages_under_5;
    double ages_under_18;
    double ages_65_or_greater;
};

int compare_by_age_65_or_gt(const void *p1, const void *p2) /* comparing the states in the file */ 
{
    const struct state *a1 = p1;
    const struct state *a2 = p2;
    
    if (a1->ages_65_or_greater < a2->ages_65_or_greater)
    {
        return 1;
    }
    else if (a1->ages_65_or_greater > a2->ages_65_or_greater)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char input_file_open[100]; 
    char output_file_name[110];

    printf("Enter the file name: \n");
    scanf("%s", input_file_open);

    FILE *input_file = fopen(input_file_open, "r"); 
    FILE *output_file;

    struct state list[100];
    int i, n = 0;

    do
    {
        fscanf(input_file, "%[^,], %d, %d, %lf, %lf, %lf\n",list[n].state_name, &list[n].population_2020,&list[n].population_2010,&list[n].ages_under_5,&list[n].ages_under_18,&list[n].ages_65_or_greater);
        n++;
    }
        while(!feof(input_file));

        fclose(input_file);
        
        qsort(list, n, sizeof(struct state), compare_by_age_65_or_gt); /* quick sort */

        strcpy(output_file_name, "sorted_"); 
        strcat(output_file_name, input_file_open);

        printf("Output file name:\n");
        printf("%s\n", output_file_name);
        printf("\n");

        output_file = fopen(output_file_name, "w");

        for(i=0; i<n; i++)
        {
            fprintf(output_file, "%s,%d,%d,%.1lf,%.1lf,%.1lf\n",list[i].state_name,list[i].population_2020,list[i].population_2010,list[i].ages_under_5,list[i].ages_under_18,list[i].ages_65_or_greater);
        }

    fclose(output_file);

return 0;
}
