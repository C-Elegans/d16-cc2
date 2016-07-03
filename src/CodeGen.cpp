//
//  CodeGen.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/3/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "CodeGen.hpp"
#include "Instruction_RI.hpp"
#include "Instruction_RR.hpp"
void CodeGen::recurse(ASTNode* ast){
	for(auto it = ast->children.begin(); it!= ast->children.end();++it){
		recurse(*it);
	}
	if(instanceOf<NumNode>(ast)){
		std::unique_ptr<MachineInstruction> m = ast->assemble();
		instructions.push_back(std::move(m));
	}
	if(instanceOf<Operator>(ast)){
		std::unique_ptr<MachineInstruction> m = ast->assemble();
		if(m != nullptr){
			instructions.push_back(std::make_unique<Instruction_RR>(POP, 1));
			instructions.push_back(std::make_unique<Instruction_RR>(POP, 0));
			instructions.push_back(std::move(m));
			instructions.push_back(std::make_unique<Instruction_RR>(PUSH,0));
		}
	}
}
CodeGen::CodeGen(ASTNode* ast){
	recurse(ast);
	for(int i=0;i<instructions.size();i++){
		instructions[i]->print();
	}
}