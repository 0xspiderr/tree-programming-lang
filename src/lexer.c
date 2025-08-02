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

char *read_identifier(Lexer_t *lexer)
{
    char *identifier = "";
    size_t start_pos = lexer->current_char_pos;
    size_t identifier_size = 0;

    while (is_letter(lexer->current_char))
    {
        read_character(lexer);
        identifier_size++;
    }

    identifier = strndup(lexer->code + start_pos, identifier_size);
    if (identifier == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for a new identifier\n");
        exit(EXIT_FAILURE);
    }

    return identifier;
}

char *read_number(Lexer_t *lexer)
{
    char *number = "";
    size_t start_pos = lexer->current_char_pos;
    size_t number_size = 0;
    while (is_digit(lexer->current_char))
    {
        read_character(lexer);
        number_size++;
    }

    number = strndup(lexer->code + start_pos, number_size);
    if (number == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for a new number\n");
        exit(EXIT_FAILURE);
    }

    return number;
}

char is_letter(char c)
{
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '_';
}

char is_digit(char d)
{
    return d >= '0' && d <= '9';
}

void kill_whitespace(Lexer_t *lexer)
{
    while (lexer->current_char == ' '
        || lexer->current_char == '\t'
        || lexer->current_char == '\r')
    {
        read_character(lexer);
    }
}

char get_next_char(Lexer_t *lexer)
{
    if (lexer->current_code_pos >= strlen(lexer->code))
        return 0;

    return lexer->code[lexer->current_code_pos];
}