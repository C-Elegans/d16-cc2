cmake_minimum_required(VERSION 3.5)
project(d16_cc2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wno-deprecated-register")
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
    src/Instruction_Mem.cpp
    src/Instruction_Mem.hpp
    src/Instruction_RI.cpp
    src/Instruction_RI.hpp
    src/Instruction_RR.cpp
    src/Instruction_RR.hpp
    src/MachineInstruction.cpp
    src/MachineInstruction.hpp
    src/OptimizePass.cpp
    src/OptimizePass.hpp
    src/ExpressionSimplifier.cpp
    src/ExpressionSimplifier.hpp
    src/CodeGen.cpp
    src/CodeGen.hpp src/Peephole.cpp src/Peephole.hpp)

add_executable(d16_cc2 ${SOURCE_FILES} ${BisonOutput} ${FlexOutput})