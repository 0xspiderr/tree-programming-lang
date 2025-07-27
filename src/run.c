/***********************************************************
* INCLUDES
 ***********************************************************/
#include "../include/run.h"

/***********************************************************
 * DEFINITIONS
 ***********************************************************/
void exec_file(char *path)
{
    FILE *file = fopen(path, "r");

    if (file == NULL)
    {
        fprintf(stderr, "'%s' file not found\n", path);
        exit(EXIT_FAILURE);
    }
}

void exec_repl()
{
    char line[MAX_LINE_LENGTH];
    while (1)
    {
        fprintf(stdout, ": ");
        fgets(line, "%s", stdin);
        if (line == NULL)
            break;
    }
}