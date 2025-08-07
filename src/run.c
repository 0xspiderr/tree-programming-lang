/***********************************************************
* INCLUDES
 ***********************************************************/
#include "../include/run.h"

#include <string.h>

#include "../include/errors.h"
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
        line[strlen(line)] = 0;

        if (line == NULL || strcmp(line, "exit\n") == 0)
            break;

        lexer = new_lexer(line);
		ASSERT_MALLOC(lexer);

        for (token = generate_token(lexer); token.type != EOF_T; token = generate_token(lexer))
        {
            fprintf(stdout, "[TYPE:'%s', LITERAL:'%s']\n", get_token_string(token.type), token.literal);
        }
    }

    destroy_lexer(&lexer);
}