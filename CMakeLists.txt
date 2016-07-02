cmake_minimum_required(VERSION 3.5)
project(d16_cc2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
FIND_PACKAGE(BISON REQUIRED)
SET(BisonOutput ${CMAKE_SOURCE_DIR}/src/parser.cpp)
IF(BISON_FOUND)
    ADD_CUSTOM_COMMAND(
            OUTPUT ${BisonOutput}
            COMMAND ${BISON_EXECUTABLE}
                --defines=${CMAKE_SOURCE_DIR}/src/parser.hpp
                --output=${BisonOutput}
                ${CMAKE_SOURCE_DIR}/src/parser.ypp
            COMMENT "Generating parser.cpp"
    )
ENDIF(BISON_FOUND)

FIND_PACKAGE(FLEX REQUIRED)
SET(FlexOutput ${CMAKE_SOURCE_DIR}/src/lex.cpp)
IF(FLEX_FOUND)
    ADD_CUSTOM_COMMAND(
            OUTPUT ${FlexOutput}
            COMMAND ${FLEX_EXECUTABLE}
                --outfile=${FlexOutput}
                ${CMAKE_SOURCE_DIR}/src/lex.lpp
            COMMENT "Generating lex.cpp"
    )
ENDIF(FLEX_FOUND)
set(SOURCE_FILES
    src/Assign.cpp
    src/Assign.hpp
    src/ASTInclude.hpp
    src/ASTNode.cpp
    src/ASTNode.hpp
    src/Call.cpp
    src/Call.hpp
    src/Eval.cpp
    src/Eval.hpp
    src/Function.cpp
    src/Function.hpp
    src/lex.lpp
    src/List.cpp
    src/List.hpp
    src/main.cpp
    src/NumNode.cpp
    src/NumNode.hpp
    src/Operator.cpp
    src/Operator.hpp
    src/Param.cpp
    src/Param.hpp
    src/parser.ypp
    src/Return.cpp
    src/Return.hpp
    src/Selection.cpp
    src/Selection.hpp
    src/type.h
    src/Var.cpp
    src/Var.hpp
    src/VarDec.cpp
    src/VarDec.hpp
    src/While.cpp
    src/While.hpp
    autogen.sh
    configure.ac
    Makefile.am
    README.md)

add_executable(d16_cc2 ${SOURCE_FILES} ${BisonOutput} ${FlexOutput})