//
//  Instruction_RR.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/3/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Instruction_RR_hpp
#define Instruction_RR_hpp

#include <stdio.h>
#include "MachineInstruction.hpp"
class Instruction_RR: public MachineInstruction {
	int rS;
	int rD;

public:
	Instruction_RR(OpType t, int rD,int rS);
	Instruction_RR(OpType t, int rD);
	virtual void assemble(uint16_t**) override;
	virtual void print() override;
};
#endif /* Instruction_RR_hpp */
