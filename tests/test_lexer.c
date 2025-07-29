#include "../tests/test_lexer.h"

#include <string.h>

/***********************************************************
 * DEFINITIONS
 ***********************************************************/
LexerTest test_single[] =
{
    {ASSIGN_T,            "="},
    {PLUS_T,              "+"},
    {LEFT_PARENTHESIS_T,  "("},
    {RIGHT_PARENTHESIS_T, ")"},
    {LEFT_BRACE_T,        "["},
    {RIGHT_BRACE_T,       "]"},
    {SEMICOLON_T,         ";"}
};

LexerTest test_program[] =
{
    {SET_T              , "set"},
    {IDENTIFIER_T       , "x"},
    {ASSIGN_T           , "="},
    {NUMBER_T           , "12"},
    {SET_T              , "set"},
    {IDENTIFIER_T       , "y"},
    {ASSIGN_T           , "="},
    {NUMBER_T           , "4"},
    {BLOCK_T            , "block"},
    {IDENTIFIER_T       , "subtract"},
    {LEFT_PARENTHESIS_T , "("},
    {IDENTIFIER_T       , "x"},
    {COMMA_T            , ","},
    {IDENTIFIER_T       , "y"},
    {RIGHT_PARENTHESIS_T, ")"},
    {IDENTIFIER_T       , "x"},
    {MINUS_T            , "-"},
    {IDENTIFIER_T       , "y"},
    {ENDBLOCK_T         , "endblock"},
    {SET_T              , "set"},
    {IDENTIFIER_T       , "ans"},
    {ASSIGN_T           , "="},
    {IDENTIFIER_T       , "subtract"},
    {LEFT_PARENTHESIS_T , "("},
    {IDENTIFIER_T       , "x"},
    {COMMA_T            , ","},
    {IDENTIFIER_T       , "y"},
    {RIGHT_PARENTHESIS_T, ")"},
    {EOF_T              , ""}
};
void test_generate_token()
{
    char source_code[] = "set x = 12 "
                         "set y = 4 "
                         "block subtract(x, y) "
                         "  x - y "
                         "endblock "
                         "set ans = subtract(x, y) ";
    size_t i = 0;
    size_t n = sizeof(test_program) / sizeof(test_program[0]);
    Lexer_t *lexer = new_lexer(source_code);
    for (i = 0; i < n; i++)
    {
        Token_t token = generate_token(lexer);
        if (token.type != test_program[i].expected_type)
        {
            fprintf(stderr, "[TEST %llu] Wrong token type. Expected '%s', got '%s'\n",
                i,
                get_token_string(test_program[i].expected_type),
                get_token_string(token.type));
        }

        if (strcmp(token.literal, test_program[i].expected_literal) != 0)
        {
            fprintf(stderr, "[TEST %llu] Wrong string literal. Expected '%s', got '%s'\n", i,
                test_program[i].expected_literal,
                token.literal);
        }
    }

    destroy_lexer(&lexer);
}