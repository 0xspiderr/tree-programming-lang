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
Lexer_t *new_lexer(const char *code)
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
        fprintf(stderr, "Failed to allocate memory for a new lexer's source code\n");
        exit(EXIT_FAILURE);
    }

    read_character(lexer);
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

void read_character(Lexer_t *lexer)
{
    if (lexer->current_code_pos >= strlen(lexer->code))
        lexer->current_char = 0;
    else
        lexer->current_char = lexer->code[lexer->current_code_pos];

    lexer->current_char_pos = lexer->current_code_pos;
    lexer->current_code_pos++;
}