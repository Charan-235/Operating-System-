// Q2:Identify the system calls to copy the content of one file to another and illustrate the same using a C program.
// Program:
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *source, *destination;
    char source_file[100];
    char destination_file[100];
    int ch;

    printf("Enter source filename: ");
    scanf("%99s", source_file);

    printf("Enter destination filename: ");
    scanf("%99s", destination_file);

    source = fopen(source_file, "r");

    if (source == NULL)
    {
        printf("Cannot open source file.\n");
        return 1;
    }

    destination = fopen(destination_file, "w");

    if (destination == NULL)
    {
        printf("Cannot open destination file.\n");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }

    printf("File copied successfully.\n");

    fclose(source);
    fclose(destination);

    return 0;
}

// Output:
// Enter the filename to open for reading 
// Exp2.txt
// Enter the filename to open for writing 
// output.txt

// Contents copied to output.txt
