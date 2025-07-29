#ifndef LEXER_H
#define LEXER_H
/***********************************************************
 * INCLUDES
 ***********************************************************/
#include <stddef.h>

/***********************************************************
 * STRUCTURES
 ***********************************************************/
typedef struct Lexer_t
{
    char    *code;              // input source code
    char     current_char;      // current char being examined
    size_t   current_code_pos;  // current reading position in the source code(after current char)
    size_t   current_char_pos;  // current reading position in the source code(points to current char)
} Lexer_t;

/***********************************************************
 * PROTOTYPES
 ***********************************************************/
Lexer_t *new_lexer      (const char *);
void     destroy_lexer  (Lexer_t **);
void     read_character (Lexer_t *);
char    *read_identifier(Lexer_t *);
char    *read_number    (Lexer_t *);
char     is_letter      (char);
char     is_digit       (char);

#endif //LEXER_H
