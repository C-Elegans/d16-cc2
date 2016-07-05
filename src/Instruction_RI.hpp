//
//  Instruction_RI.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/3/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Instruction_RI_hpp
#define Instruction_RI_hpp

#include <stdio.h>
#include "MachineInstruction.hpp"
class Instruction_RI: public MachineInstruction {


public:
	int immediate;
	int rD;
	Instruction_RI(OpType t, int rD,int immediate);
	Instruction_RI(OpType t, int immediate);
	virtual void assemble(uint16_t**) override;
	virtual void print() override;
};
#endif /* Instruction_RI_hpp */
