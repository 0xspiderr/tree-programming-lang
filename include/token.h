#ifndef TOKEN_H
#define TOKEN_H
/***********************************************************
 * INCLUDES
 ***********************************************************/
#include <stddef.h>
#include "../include/lexer.h"

/***********************************************************
 * ENUMS
 ***********************************************************/
typedef enum TokenType
{
    // ARITHMETIC
    PLUS_T, MINUS_T,
    ASTERISK_T, SLASH_T,

    // PARENTHESIS
    LEFT_PARENTHESIS_T, RIGHT_PARENTHESIS_T,
    LEFT_BRACE_T, RIGHT_BRACE_T,

    // COMMENTS / SEPARATORS
    SEMICOLON_T, COMMA_T,

    // LOGIC
    EQUAL_T, NOT_EQUAL_T, LESS_T,
    GREATER_T, LESS_EQUAL_T, GREATER_EQUAL_T,
    ASSIGN_T,

    // LITERALS
    IDENTIFIER_T, NUMBER_T,

    // KEYWORDS
    AND_T, OR_T, IF_T, ELSE_T, ELSE_IF_T,
    TRUE_T, FALSE_T, SET_T, WHILE_T, RETURN_T,
    BLOCK_T,

    // TERMINATORS
    ENDIF_T, ENDBLOCK_T,

    // SPECIAL
    EOF_T, ILLEGAL_T
} TokenType;

/***********************************************************
 * STRUCTURES
 ***********************************************************/
typedef struct Token_t
{
    TokenType type;
    char      *literal;
} Token_t;

/***********************************************************
 * DATA
 ***********************************************************/
static char *token_strings[] =
{
    // ARITHMETIC
    "+", "-", "*", "/",
    // PARENTHESIS
    "(", ")", "[", "]",
    // COMMENTS / SEPARATORS
    ";", ",",
    // LOGIC
    "==", "!=", "<", ">", "<=", ">=", "=",
    // KEYWORDS
    "and", "or", "if", "else", "else if",
    "true", "false", "set", "while", "return",
    "block",
    // TERMINATORS
    "endif", "endblock",
    // SPECIAL
    "eof", "illegal"
};

static Token_t keywords[] =
{
    {IF_T      , "if"},
    {ELSE_IF_T , "else if"},
    {ELSE_T    , "else"},
    {ENDIF_T   , "endif"},
    {SET_T     , "set"},
    {RETURN_T  , "return"},
    {BLOCK_T   , "block"},
    {ENDBLOCK_T, "endblock"}
};

/***********************************************************
 * PROTOTYPES
 ***********************************************************/
Token_t    generate_token  (Lexer_t *);
Token_t    new_token       (TokenType);
char      *get_token_string(TokenType);
TokenType  get_keyword     (char *);
void       kill_whitespace (Lexer_t *);

#endif //TOKEN_H
