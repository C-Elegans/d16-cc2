//
//  CodeGen.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/3/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "CodeGen.hpp"
#include "Instruction_RI.hpp"
void CodeGen::recurse(ASTNode* ast){
	for(auto it = ast->children.begin(); it!= ast->children.end();++it){
		recurse(*it);
	}
	if(instanceOf<NumNode>(ast)){
		NumNode* n = static_cast<NumNode*>(ast);
		instructions.push_back(new Instruction_RI(PUSH,n->value));
	}
}
CodeGen::CodeGen(ASTNode* ast){
	recurse(ast);
	for(auto it = instructions.begin(); it != instructions.end(); ++it){
		MachineInstruction* m = *it;
		m->print();
	}
}