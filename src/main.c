#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PATH getenv("PATH")

bool file_exists(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file)
    {
        fclose(file);
        return true;
    }
    return false;
}

void nwline(void)
{
    printf("\n$ ");
}

int main(void)
{
    if (PATH == NULL || PATH[0] == '\0')
    {
        printf("Program path is not set.\n");
        return 1;
    }
    char *instr = malloc(2048);
    scanf("%s", instr);
    char *splittedPath = strtok(PATH, ":");
    while (splittedPath != NULL)
    {
        char *path = malloc(strlen(splittedPath) + strlen(instr) + 2);
        strcpy(path, splittedPath);
        strcat(path, "/");
        strcat(path, instr);

        if (file_exists(path))
        {
            

            return 0;
        }

        splittedPath = strtok(NULL, ":");
    }

    return 0;
}