cmake_minimum_required(VERSION 3.25.1)
project(tree C)

set(CMAKE_C_STANDARD 11)

add_executable(ctree src/tree.c
        src/run.c
        include/run.h
        src/token.c
        include/token.h
        src/lexer.c
        include/lexer.h
        src/ast.c
        include/ast.h
        src/parser.c
        include/parser.h
        include/errors.h
        test/src/test_lexer.c
        test/include/test_lexer.h
        test/src/test_parser.c
        test/include/test_parser.h

)



