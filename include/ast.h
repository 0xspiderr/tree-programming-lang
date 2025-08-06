#ifndef AST_H
#define AST_H
/***********************************************************
 * INCLUDES
 ***********************************************************/
#include "token.h"

/***********************************************************
 * STRUCTURES / UNIONS
 ***********************************************************/
typedef struct Identifier_t
{
	Token_t token; // IDENTIFIER_T
	char   *value;
} Identifier_t;

typedef struct Expression_t
{
} Expression_t;

typedef struct SetStatement_t
{
	Token_t		 token; // SET_T
	Identifier_t name;
	Expression_t value;
} SetStatement_t;

typedef union StatementTypes_t
{
	SetStatement_t set;
} StatementTypes_t;

typedef struct Statement_t
{
	StatementTypes_t type;
} Statement_t;

typedef struct Program_t
{
	Statement_t *statements;
} Program_t;

/***********************************************************
 * PROTOTYPES
 ***********************************************************/

#endif //AST_H
