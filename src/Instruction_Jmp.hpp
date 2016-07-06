//
//  Instruction_Jmp.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 2016-07-06.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Instruction_Jmp_hpp
#define Instruction_Jmp_hpp
#include "MachineInstruction.hpp"
#include <stdio.h>
enum class ConditionCode{
    NV = 0,
    EQ,
    NE,
    OS,
    OC,
    HI,
    LS,
    P,
    N,
    CS,
    CC,
    GE,
    G,
    LE,
    L,
    AL=15
};
class Instruction_Jmp: public MachineInstruction {
    int rD;
    ConditionCode cc;
public:
    Instruction_Jmp(OpType t, ConditionCode cc, int rD);

    virtual void assemble(uint16_t**) override;
    virtual void print() override;
};
#endif /* Instruction_Jmp_hpp */
