#ifndef LEXER_H
#define LEXER_H
#include "token.h"

/***********************************************************
 * STRUCTURES
 ***********************************************************/
typedef struct Lexer_t
{
    char    *code;
    Token_t *tokens;
} Lexer_t;

/***********************************************************
 * PROTOTYPES
 ***********************************************************/
Lexer_t *new_lexer    (char *);
void     destroy_lexer(Lexer_t **);

#endif //LEXER_H
