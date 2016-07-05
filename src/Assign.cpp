//
//  Assign.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Assign.hpp"
#include "Instruction_Mem.hpp"
#include "Instruction_RR.hpp"
Assign::Assign(ASTNode* lval, ASTNode* rval){
	add_child(lval);
	add_child(rval);
}
void Assign::printElem(){
	printf("Assign:\n");
}
std::vector<std::unique_ptr<MachineInstruction>> Assign::post_assemble(void){
	Var* var = static_cast<Var*>(children[0]);
	std::vector<std::unique_ptr<MachineInstruction>> v;
	v.push_back(std::make_unique<Instruction_RR>(POP, 0));
	v.push_back(std::make_unique<Instruction_Mem>(ST, 6, 0, var->address, true));
	return v;
}