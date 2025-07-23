/***********************************************************
* INCLUDES
 ***********************************************************/
#include "../include/lexer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************************************
 * DEFINITIONS
 ***********************************************************/
Lexer_t *new_lexer(char *code)
{
    assert(code != NULL);

    Lexer_t *lexer = (Lexer_t *)malloc(sizeof(Lexer_t));

    if (lexer == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for a new lexer\n");
        exit(EXIT_FAILURE);
    }

    lexer->code = strdup(code);
    if (lexer->code == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for a new lexer\n");
        exit(EXIT_FAILURE);
    }
    return lexer;
}

void destroy_lexer(Lexer_t **lexer)
{
    assert(lexer != NULL);
    assert((*lexer)->code != NULL);

    free((*lexer)->code);
    (*lexer)->code = NULL;

    free(*lexer);
    *lexer = NULL;
}