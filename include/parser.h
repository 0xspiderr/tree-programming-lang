#ifndef PARSER_H
#define PARSER_H
/***********************************************************
 * INCLUDES
 ***********************************************************/
#include "ast.h"
#include "lexer.h"
#include "token.h"

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
Parser_t  *new_parser   (Lexer_t *);
void       next_token   (Parser_t *);
Program_t *parse_program(Parser_t *);

#endif //PARSER_H
