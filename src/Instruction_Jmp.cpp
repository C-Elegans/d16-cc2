//
//  Instruction_Jmp.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 2016-07-06.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Instruction_Jmp.hpp"
static const char* cc_strings[] = {"nv","eq","ne","os","oc","hi","ls","p","n","cs","cc","ge","g","le","l","al"};
Instruction_Jmp::Instruction_Jmp(OpType t, ConditionCode _cc, int _rD){
    type = t;
    cc = _cc;
    rD = _rD;
}
void Instruction_Jmp::assemble(uint16_t ** data){
    **data = type <<8 | (static_cast<int>(cc) & 0xf)<<3 | (rD&7);
    ++*data;
}
void Instruction_Jmp::print(){
    printType();
    printf(".%s r%d\n",cc_strings[static_cast<int>(cc)],rD);
}