//
//  Operator.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Operator.hpp"
#include <stdlib.h>
#include "Instruction_RR.hpp"
#include "Instruction_Jmp.hpp"
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
std::vector<std::unique_ptr<MachineInstruction>> Operator::post_assemble(){
	std::vector<std::unique_ptr<MachineInstruction>> v;
	v.push_back(std::make_unique<Instruction_RR>(POP,1));
	v.push_back(std::make_unique<Instruction_RR>(POP,0));
	switch(type){
		case Operator_type::ADD:
			v.push_back(std::make_unique<Instruction_RR>(ADD,0,1));
			break;
		case Operator_type::SUBTRACT:
			v.push_back(std::make_unique<Instruction_RR>(SUB,0,1));
			break;
        case Operator_type::CMP_EQ:
            v.push_back(std::make_unique<Instruction_RR>(CMP,0,1));
            v.push_back(std::make_unique<Instruction_Jmp>(SET,ConditionCode::EQ,0));
            break;
        case Operator_type::CMP_NE:
            v.push_back(std::make_unique<Instruction_RR>(CMP,0,1));
            v.push_back(std::make_unique<Instruction_Jmp>(SET,ConditionCode::NE,0));
            break;
        case Operator_type::CMP_GE:
            v.push_back(std::make_unique<Instruction_RR>(CMP,0,1));
            v.push_back(std::make_unique<Instruction_Jmp>(SET,ConditionCode::GE,0));
            break;
        case Operator_type::CMP_GT:
            v.push_back(std::make_unique<Instruction_RR>(CMP,0,1));
            v.push_back(std::make_unique<Instruction_Jmp>(SET,ConditionCode::G,0));
            break;
        case Operator_type::CMP_LT:
            v.push_back(std::make_unique<Instruction_RR>(CMP,0,1));
            v.push_back(std::make_unique<Instruction_Jmp>(SET,ConditionCode::L,0));
            break;
        case Operator_type::CMP_LE:
            v.push_back(std::make_unique<Instruction_RR>(CMP,0,1));
            v.push_back(std::make_unique<Instruction_Jmp>(SET,ConditionCode::LE,0));
            break;
        case Operator_type::O_OR:
            v.push_back(std::make_unique<Instruction_RR>(OR,0,1));
            break;
        case Operator_type::O_AND:
            v.push_back(std::make_unique<Instruction_RR>(AND,0,1));
            break;
        case Operator_type::O_XOR:
            v.push_back(std::make_unique<Instruction_RR>(XOR,0,1));
            break;
		default:
			fprintf(stderr, "Operation not supported\n");
			exit(-1);
			break;
	}
	v.push_back(std::make_unique<Instruction_RR>(PUSH,0));
	return v;
}