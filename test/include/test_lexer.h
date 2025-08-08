#ifndef TEST_LEXER_H
#define TEST_LEXER_H
/***********************************************************
 * INCLUDES
 ***********************************************************/
#include <stdio.h>
#include "../../include/lexer.h"
#include "../../include/token.h"

/***********************************************************
 * STRUCTURES
 ***********************************************************/
typedef struct LexerTest
{
	TokenType expected_type;
	char     *expected_literal;
} LexerTest;

/***********************************************************
 * TESTS
 ***********************************************************/
void test_generate_token();

#endif //TEST_LEXER_H