#ifndef ERRORS_H
#define ERRORS_H

/***********************************************************
 * MACROS
 ***********************************************************/
#define TEST_EQ_STR(expected, actual) \
	if(strcmp(expected, actual) != 0) {	\
		fprintf(stderr, "[TEST FAILED]: expected '%s' got '%s' in file:'%s' at line '%d'\n", (expected), (actual), __FILE__, __LINE__); \
	}	\

#define TEST_EQ_TOK(expected, actual) \
	if((expected) != (actual)) {	\
		fprintf(stderr, "[TEST FAILED]: expected '%s' got '%s' in file:'%s' at line '%d'\n", get_token_string(expected), get_token_string(actual), __FILE__, __LINE__); \
	}	\

#define TEST_EQ_INT(expected, actual) \
	if(expected != actual) {	\
		fprintf(stderr, "[TEST FAILED]: expected '%lu' got '%llu' in file:'%s' at line:'%d'\n", (expected), (actual), __FILE__, __LINE__); \
	}	\


#define ASSERT_EQ_STR(expected, actual) \
	if(strcmp(expected, actual) != 0) {	\
		fprintf(stderr, "[TEST FAILED]: expected '%s' got '%s' in file:'%s' at line '%d'\n", (expected), (actual), __FILE__, __LINE__); \
		exit(EXIT_FAILURE);	\
	}	\

#define ASSERT_MALLOC(ptr) \
	if((ptr) == NULL) {	\
		fprintf(stderr, "[MALLOC FAILED]: memory allocation failed in file '%s' at line '%d'\n", __FILE__, __LINE__); \
		exit(EXIT_FAILURE);	\
	}	\



#endif //ERRORS_H