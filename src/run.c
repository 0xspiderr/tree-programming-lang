/***********************************************************
* INCLUDES
 ***********************************************************/
#include "../include/run.h"

#include "../include/lexer.h"
#include "../include/token.h"

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
    Lexer_t *lexer = NULL;
    Token_t token = {0};

    while (1)
    {
        fprintf(stdout, "tree: ");
        fgets(line, MAX_LINE_LENGTH, stdin);
        if (line == NULL)
            break;

        lexer = new_lexer(line);
        if (lexer == NULL)
        {
            fprintf(stderr, "'%s' lexer not found\n", line);
            exit(EXIT_FAILURE);
        }

        for (token = generate_token(lexer); token.type != EOF_T; token = generate_token(lexer))
        {
            fprintf(stdout, "[TYPE:'%s', LITERAL:'%s']\n", get_token_string(token.type), token.literal);
        }
    }

    destroy_lexer(&lexer);
}