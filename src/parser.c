/***********************************************************
 * INCLUDES
 ***********************************************************/
#include "../include/parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/errors.h"

/***********************************************************
 * DEFINITIONS
 ***********************************************************/
Parser_t *new_parser(Lexer_t *lexer)
{
	Parser_t *parser = (Parser_t *)malloc(sizeof(Parser_t));

	ASSERT_MALLOC(parser);

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
	Program_t *program = (Program_t *)malloc(sizeof(Program_t));
	ASSERT_MALLOC(program);
	// TODO: change this allocation, now we allocated only 10 for testing purposes
	program->statements = (Statement_t *)malloc(sizeof(Statement_t) * 10);
	ASSERT_MALLOC(program->statements);
	program->size = 0;

	while (parser->current_token.type != EOF_T)
	{
		Statement_t *statement = parse_statement(parser);

		if (statement != NULL)
		{
			program->statements[program->size++] = *statement;
		}

		next_token(parser);
	}

	return program;
}

Statement_t *parse_statement(Parser_t *parser)
{
	switch (parser->current_token.type)
	{
		case SET_T:
			return parse_set_statement(parser);
		default:
			return NULL;
	}
}

Statement_t *parse_set_statement(Parser_t *parser)
{
	Statement_t *statement = (Statement_t *)malloc(sizeof(Statement_t));
	ASSERT_MALLOC(statement);
	statement->type.set.token = parser->current_token;

	if (!expected_peek(IDENTIFIER_T, parser))
	{
		free(statement);
		return NULL;
	}

	Identifier_t identifier = { 0 };
	identifier.token = parser->current_token;
	identifier.value = parser->current_token.literal;
	statement->type.set.name = identifier;

	if (!expected_peek(ASSIGN_T, parser))
	{
		free(identifier.value);
		free(statement);
		return NULL;
	}

	while (parser->current_token.type != NEW_LINE_T)
	{
		next_token(parser);
	}

	return statement;
}

uint8_t current_token_eq(TokenType type, Parser_t parser)
{
	return type == parser.current_token.type;
}

uint8_t peek_token_eq(TokenType type, Parser_t parser)
{
	return type == parser.peek_token.type;
}

uint8_t expected_peek(TokenType type, Parser_t *parser)
{
	if (peek_token_eq(type, *parser))
	{
		next_token(parser);
		return 1;
	}

	return 0;
}