/***********************************************************
 * INCLUDES
 ***********************************************************/
#include "../include/test_parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/errors.h"
#include "../../include/lexer.h"
#include "../../include/parser.h"

/***********************************************************
 * TESTS
 ***********************************************************/
void test_set_statements()
{
	char source[] = "set x = 5\n"
					"set y = 15\n"
					"set z = 500000\n";
	char *expected[] = {"x", "y", "z"};

	Lexer_t *lexer = new_lexer(source);
	Parser_t *parser = new_parser(lexer);
	Program_t *program = parse_program(parser);

	ASSERT_MALLOC(program);
	TEST_EQ_INT(program->size, 3ull);

	size_t i = 0;

	for (i = 0; i < program->size; i++)
	{
		Statement_t st = program->statements[i];
		ASSERT_EQ_STR(st.type.set.token.literal, "set");
		ASSERT_EQ_STR(st.type.set.name.value, expected[i]);
	}
}
