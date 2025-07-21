#ifndef RUN_H
#define RUN_H
#include <stdio.h>
#include <stdlib.h>

/***********************************************************
 * NOTE: The tree programming language interpreter supports
 * two ways of running code:
 * - pass a file and it will read it and execute it;
 * - start a REPL(read line, evaluate, print, loop);
 ***********************************************************/

/***********************************************************
 * DEFINES
 ***********************************************************/
#define MAX_LINE_LENGTH 1024

/***********************************************************
 * PROTOTYPES
 ***********************************************************/
void exec_file(char *);
void exec_repl(void);

#endif //RUN_H
