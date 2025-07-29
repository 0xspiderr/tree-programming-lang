#include "../include/token.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

Token_t generate_token(Lexer_t *lexer)
{
    assert(lexer != NULL);

    Token_t token = {0};

    kill_whitespace(lexer);

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
        case ',':
            token = new_token(COMMA_T);
            break;
        case '\0':
            token.type = EOF_T;
            token.literal = "";
            return token;
            break;
        default:
            if (is_letter(lexer->current_char))
            {
                token.literal = read_identifier(lexer);
                token.type    = get_keyword(token.literal);
                return token;
            }
            else if (is_digit(lexer->current_char))
            {
                token.literal = read_number(lexer);
                token.type    = NUMBER_T;
                return token;
            }
            else
                token = new_token(ILLEGAL_T);
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

TokenType get_keyword(char *identifier)
{
    size_t size = sizeof(keywords) / sizeof(keywords[0]);
    size_t i;

    for (i = 0; i < size; i++)
    {
        if (strcmp(identifier, keywords[i].literal) == 0)
            return keywords[i].type;
    }

    return IDENTIFIER_T;
}

void kill_whitespace(Lexer_t *lexer)
{
    while (lexer->current_char == ' '
        || lexer->current_char == '\t'
        || lexer->current_char == '\n'
        || lexer->current_char == '\r')
    {
        read_character(lexer);
    }
}