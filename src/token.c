/***********************************************************
 * INCLUDES
 ***********************************************************/
#include "../include/token.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../include/errors.h"

/***********************************************************
 * DEFINITIONS
 ***********************************************************/
Token_t generate_token(Lexer_t *lexer)
{
    assert(lexer != NULL);

    Token_t token = {0};

    kill_whitespace(lexer);

    switch (lexer->current_char)
    {
        // ARITHMETIC
        case '+':
            token = new_token(PLUS_T);
            break;
        case '-':
            token = new_token(MINUS_T);
            break;
        case '*':
            token = new_token(MULTIPLY_T);
            break;
        case '/':
            token = new_token(DIVIDE_T);
            break;
        // PARENTHESIS
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
        // COMMENTS / SEPARATORS
        case ';':
            token = new_token(SEMICOLON_T);
            break;
        case ',':
            token = new_token(COMMA_T);
            break;
        case '\n':
            token = new_token(NEW_LINE_T);
            break;
        // LOGIC
        case '=':
            if (get_next_char(lexer) == '=')
            {
                read_character(lexer);
                token = new_token(EQUAL_T);
            }
            else
            {
                token = new_token(ASSIGN_T);
            }
            break;
        case '!':
            if (get_next_char(lexer) == '=')
            {
                read_character(lexer);
                token = new_token(NOT_EQUAL_T);
            }
            else
            {
                token = new_token(NOT_T);
            }
            break;
        case '>':
            if (get_next_char(lexer) == '=')
            {
                read_character(lexer);
                token = new_token(GREATER_EQUAL_T);
            }
            else
            {
                token = new_token(GREATER_T);
            }
            break;
        case '<':
            if (get_next_char(lexer) == '=')
            {
                read_character(lexer);
                token = new_token(LESS_EQUAL_T);
            }
            else
            {
                token = new_token(LESS_T);
            }
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

	ASSERT_MALLOC(token.literal);

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
