//
//  Operator.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Operator.hpp"
#include "Instruction_RR.hpp"
				//PLUS,MINUS,MULTIPLY,DIVIDE,CMP_EQ,CMP_NE,CMP_GT,CMP_LT,CMP_GE,CMP_LE
static const char* type_strings[] = {"+","-","*","/","==","!=",">","<",">=","<="};
Operator::Operator(Operator_type _type,AST_ptr _child1, AST_ptr _child2){
	type = _type;
	add_child(_child1);
	add_child(_child2);
}
void Operator::printElem(){

	printf("Operator: %s\n",type_strings[static_cast<int>(type)]);

}
std::unique_ptr<MachineInstruction> Operator::assemble(){
	std::unique_ptr<MachineInstruction> m;
	switch(type){
		case Operator_type::ADD:
			m = std::make_unique<Instruction_RR>(ADD,0,1);
			break;
		default:
			m = nullptr;
			break;
	}
	return m;
}