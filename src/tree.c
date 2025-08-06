#include "../include/parser.h"
#include "../include/run.h"
#include "../tests/test_lexer.h"

void main(int argc, char **argv)
{
    //exec_repl();

	Lexer_t *lexer = new_lexer("set val = 5\n");
	Parser_t *parser = new_parser(lexer);

	printf("%s %s\n", parser->current_token.literal, parser->peek_token.literal);

	free(parser);
	parser = NULL;

	destroy_lexer(&lexer);
}
