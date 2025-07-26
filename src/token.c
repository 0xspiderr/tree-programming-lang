#include "../include/token.h"
#include <assert.h>

Token_t generate_token(Lexer_t *lexer)
{
    assert(lexer != NULL);

    Token_t token = {0};

    switch (lexer->current_char)
    {
        case '=':
            break;
        default:
            break;
    }

    return token;
}
