cmake_minimum_required(VERSION 3.25.1)
project(tree_programming_lang C)

set(CMAKE_C_STANDARD 11)

add_executable(tree_programming_lang src/tree.c
        src/run.c
        include/run.h
        src/token.c
        include/token.h
        src/lexer.c
        include/lexer.h
        tests/test_lexer.c
        tests/test_lexer.h)
