//
//  Eval.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Eval.hpp"
#include "Instruction_RI.hpp"
#include "Instruction_RR.hpp"
#include "Instruction_Mem.hpp"
Eval::Eval(ASTNode* a){
	add_child(a);
}
void Eval::printElem(){
	printf("Eval:\n");
}
std::vector<std::unique_ptr<MachineInstruction>> Eval::post_assemble(void){
	Var* var = static_cast<Var*>(children[0]);
	std::vector<std::unique_ptr<MachineInstruction>> v;
	v.push_back(std::make_unique<Instruction_Mem>(LD, 0,6,var->address,true));
	v.push_back(std::make_unique<Instruction_RR>(PUSH,0));
	return v;
}