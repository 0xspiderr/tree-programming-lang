#include "../include/token.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Token_t generate_token(Lexer_t *lexer)
{
    assert(lexer != NULL);

    Token_t token = {0};

    switch (lexer->current_char)
    {
        case '=':
            token = new_token(ASSIGN_T);
            break;
        case '+':
            token = new_token(PLUS_T);
            break;
        case '-':
            token = new_token(MINUS_T);
            break;
        case '*':
            token = new_token(ASTERISK_T);
            break;
        case '/':
            token = new_token(SLASH_T);
            break;
        case '(':
            token = new_token(LEFT_PARENTHESIS_T);
            break;
        case ')':
            token = new_token(RIGHT_PARENTHESIS_T);
            break;
        case '[':
            token = new_token(LEFT_BRACE_T);
            break;
        case ']':
            token = new_token(RIGHT_BRACE_T);
            break;
        case ';':
            token = new_token(SEMICOLON_T);
            break;
        default:
            break;
    }

    read_character(lexer);

    return token;
}

Token_t new_token(TokenType type)
{
    Token_t token = {0};
    token.type = type;
    token.literal = strdup(get_token_string(type));

    if (token.literal == NULL)
    {
        fprintf(stderr, "Failed allocation for new token literal\n");
        exit(EXIT_FAILURE);
    }

    return token;
}

char *get_token_string(TokenType type)
{
    return token_strings[type];
}