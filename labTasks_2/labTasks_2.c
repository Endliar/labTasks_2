#pragma warning(disable : 4996)
#include <stdio.h>

void createFile(const char* filename, int num_lines) 
{
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        for (int i = 0; i <= num_lines; i++)
        {
            fprintf(file, "This is the line number %d\n", i);
        }
        fclose(file);
    }
    else {
        printf("Error creating the file %s", filename);
    }
}

int copyFileWithoutSpaces(const char* sourceFilename, const char* destFilename)
{
    FILE* sourceFile = fopen(sourceFilename, "r");
    FILE* destFile = fopen(destFilename, "w");
    if (sourceFile == NULL || destFile == NULL)
    {
        printf("Error opening files");
        return 1;
    }

    int ch;
    int spacesRemoved = 0;

    while ((ch = fgetc(sourceFile)) != EOF)
    {
        if (ch != ' ')
        {
            fputc(ch, destFile);
        }
        else {
            spacesRemoved++;
        }
    }

    fclose(sourceFile);
    fclose(destFile);

    return spacesRemoved;
}

int main()
{
    const char* sourceFilename = "example.txt";
    const char* destFilename = "destination.txt";
    int num_lines = 10;

    createFile(sourceFilename, num_lines);
    int spacesRemoved = copyFileWithoutSpaces(sourceFilename, destFilename);
    printf("Spaces removed %d", spacesRemoved);

    return 0;
}