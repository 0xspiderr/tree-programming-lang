/***********************************************************
 * INCLUDES
 ***********************************************************/
#include "../include/parser.h"

#include <stdio.h>
#include <stdlib.h>

/***********************************************************
 * DEFINITIONS
 ***********************************************************/
Parser_t *new_parser(Lexer_t *lexer)
{
	Parser_t *parser = (Parser_t *)malloc(sizeof(Parser_t));

	if (parser == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for Parser_t\n");
		exit(EXIT_FAILURE);
	}

	parser->lexer = lexer;
	next_token(parser);
	next_token(parser);

	return parser;
}

void next_token(Parser_t *parser)
{
	parser->current_token = parser->peek_token;
	parser->peek_token	  = generate_token(parser->lexer);
}

Program_t *parse_program(Parser_t *parser)
{
	return NULL;
}