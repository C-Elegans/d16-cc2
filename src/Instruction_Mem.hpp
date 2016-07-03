//
//  Instruction_Mem.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/3/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Instruction_Mem_hpp
#define Instruction_Mem_hpp
#include "MachineInstruction.hpp"
#include <stdio.h>
class Instruction_Mem: public MachineInstruction {
	int rS;
	int rD;
	int immediate;
	bool displacement;
	bool imm;
public:
	Instruction_Mem(OpType t, int rD, int rS);
	Instruction_Mem(OpType t, int rD, int rS, int imm, bool displacement);
	virtual void assemble(uint16_t**) override;
	virtual void print() override;
};
#endif /* Instruction_Mem_hpp */
