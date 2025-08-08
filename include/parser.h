#ifndef PARSER_H
#define PARSER_H
/***********************************************************
 * INCLUDES
 ***********************************************************/
#include "ast.h"
#include "lexer.h"
#include "token.h"
#include "stdint.h"

/***********************************************************
 * STRUCTURES
 ***********************************************************/
typedef struct Parser_t
{
	Lexer_t *lexer;
	Token_t  current_token;
	Token_t  peek_token;
} Parser_t;

/***********************************************************
 * PROTOTYPES
 ***********************************************************/
Parser_t    *new_parser			(Lexer_t *);
void         next_token			(Parser_t *);
Program_t   *parse_program		(Parser_t *);
Statement_t *parse_statement	(Parser_t *);
Statement_t *parse_set_statement(Parser_t *);
uint8_t      current_token_eq	(TokenType, Parser_t);
uint8_t      peek_token_eq		(TokenType, Parser_t);
uint8_t		 expected_peek		(TokenType, Parser_t *);

#endif //PARSER_H
