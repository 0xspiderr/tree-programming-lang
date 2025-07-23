#include <stdio.h>
#include <string.h>

#include "../include/lexer.h"
#include "../include/run.h"

int main(int argc, char **argv)
{
    char code[] = "hello world!";

    Lexer_t *lexer = new_lexer(code);
    size_t i = 0;
    while (lexer->code[i++] != '\0')
    {
        printf("h\n");
    }

    destroy_lexer(&lexer);
    return 0;
}
