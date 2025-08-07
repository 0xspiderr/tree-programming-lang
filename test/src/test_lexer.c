#include "../include/test_lexer.h"
#include <string.h>

#include "../../include/errors.h"

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
    {PLUS_T             , "+"},
    {MINUS_T            , "-"},
    {ASSIGN_T           , "="},
    {DIVIDE_T           , "/"},
    {MULTIPLY_T         , "*"},
    {NUMBER_T           , "12"},
    {GREATER_T          , ">"},
    {NUMBER_T           , "4"},
    {IF_T               , "if"},
    {LEFT_PARENTHESIS_T , "("},
    {NUMBER_T           , "4"},
    {GREATER_T          , ">"},
    {NUMBER_T           , "12"},
    {RIGHT_PARENTHESIS_T, ")"},
    {RETURN_T           , "return"},
    {TRUE_T             , "true"},
    {ELSE_T             , "else"},
    {RETURN_T           , "return"},
    {FALSE_T            , "false"},
    {ENDIF_T            , "endif"},
    {NUMBER_T           , "12"},
    {EQUAL_T            , "=="},
    {NUMBER_T           , "12"},
    {NUMBER_T           , "4"},
    {NOT_EQUAL_T        , "!="},
    {NUMBER_T           , "12"},
    {EOF_T              , ""}
};
void test_generate_token()
{
    char source_code[] = "set x = 12 "
                         "set y = 4 "
                         "block subtract(x, y) "
                         "  x - y "
                         "endblock "
                         "set ans = subtract(x, y) "
                         "+-=/* "
                         "12 > 4 "
                         "if(4 > 12)"
                         "  return true "
                         "else "
                         "  return false "
                         "endif "
                         "12 == 12 "
                         "4 != 12 ";
    size_t i = 0;
    size_t n = sizeof(test_program) / sizeof(test_program[0]);
    Lexer_t *lexer = new_lexer(source_code);
    for (i = 0; i < n; i++)
    {
        Token_t token = generate_token(lexer);

		TEST_EQ_TOK(test_program[i].expected_type, token.type);
        TEST_EQ_STR(test_program[i].expected_literal, token.literal);
    }

    destroy_lexer(&lexer);
}

