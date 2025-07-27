#include "../tests/test_lexer.h"

#include <string.h>

/***********************************************************
 * DEFINITIONS
 ***********************************************************/
LexerTest tests[] =
{
    {ASSIGN_T,            "="},
    {PLUS_T,              "+"},
    {LEFT_PARENTHESIS_T,  "("},
    {RIGHT_PARENTHESIS_T, ")"},
    {LEFT_BRACE_T,        "["},
    {RIGHT_BRACE_T,       "]"},
    {SEMICOLON_T,         ";"}
};

void test_generate_token()
{
    char source_code[] = "=+()[];";

    Lexer_t *lexer = new_lexer(source_code);

    size_t i = 0;
    size_t n = sizeof(tests) / sizeof(tests[0]);
    for (i = 0; i < n; i++)
    {
        Token_t token = generate_token(lexer);
        if (token.type != tests[i].expected_type)
        {
            fprintf(stderr, "[TEST %llu] Wrong token type. Expected %s, got %s\n", i, get_token_string(tests[i].expected_type),
                                                                        get_token_string(token.type));
        }

        if (strcmp(token.literal, tests[i].expected_literal) != 0)
        {
            fprintf(stderr, "[TEST %llu] Wrong string literal. Expected %s, got %s\n", i,
                                                                                           tests[i].expected_literal,
                                                                                           token.literal);
        }
    }

    destroy_lexer(&lexer);
}