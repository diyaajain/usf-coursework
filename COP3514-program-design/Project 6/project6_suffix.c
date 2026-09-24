/* Name: Diya Jain U81673988*/
/* This is a program the puts words together untill the limit the user wants to.*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int m;
    char **count;
    FILE *file;
    char output_file[1000]; /* made arrays for storing the variables */
    char input_file[1000];

    printf("Enter the value of M: \n");
    scanf("%d", &m);

    for (count = argv +1; count<argv + argc; count++) /* using the arthimetic addition moving forwward */
    {
        file = fopen(*count, "r"); /* openoing the files */
        strcpy(output_file, "");
        while(!feof (file) && !ferror(file)) /* if the file has any errors */
        {
        if (fscanf(file, "%s \n", input_file) == 1) 
        {
            if ((strlen(output_file) + strlen(input_file)) <=m)
            {
                strcat(output_file, input_file);
            }
            else
            {
                strcpy(output_file, "");
                strcpy(output_file, input_file);
            }
        }
        else
        {
            return 1;
        }
        }
    printf("%s: %s \n", *count , output_file); /* prints the answer */
    fclose(file); /* closes the file */
    }
    return 0;
}