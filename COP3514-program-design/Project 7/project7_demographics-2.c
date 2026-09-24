/* Name: Diya Jain U81673988 */
/* This program sort the states by percentage of population whose ages are equal or greater than 65 years old */
#include <stdio.h>
#include <string.h>

struct state  /* made the structure for the state with the following fields */
{
    char state_name[150];
    int population_2020;
    int population_2010;
    double ages_under_5;
    double ages_under_18;
    double ages_65_or_greater;
};

void sort_states(struct state list[], int n) /* sorting the field using the selection sort */
{
    int i, j, p;
    struct state temp;

    for(i=0; i<n; i++)
    {
        p = i;
        for(j=i+1; j<n; j++)
        {
            if(list[p].ages_65_or_greater < list[j].ages_65_or_greater)
            {
                p = j;
            }
        }
        temp = list[p];
        list[p] = list[i];
        list[i] = temp;
    }
}

int main()
{
    char input_file_open[100]; /* intializing the variables */
    char output_file_name[110];

    printf("Enter the file name: \n");
    scanf("%s", input_file_open);

    FILE *input_file = fopen(input_file_open, "r"); /* opening the file with the read command */
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

        for(i=0; i<n; i++)
        {
            sort_states(list, n);
        }

        strcpy(output_file_name, "sorted_"); /* making the name of the new file */
        strcat(output_file_name, input_file_open);

        printf("Output file name:\n");
        printf("%s\n", output_file_name);
        printf("\n");

        output_file = fopen(output_file_name, "w");

        for(i=0; i<n; i++)
        {
            fprintf(output_file, "%s,%d,%d,%.1lf,%.1lf,%.1lf\n",list[i].state_name,list[i].population_2020,list[i].population_2010,list[i].ages_under_5,list[i].ages_under_18,list[i].ages_65_or_greater);
        }

    fclose(output_file); /* closing the files after storing the sorted data */

return 0;
}
