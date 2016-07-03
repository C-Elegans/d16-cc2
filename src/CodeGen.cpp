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

	std::vector<std::unique_ptr<MachineInstruction>> pre = ast->pre_assemble();
	instructions.insert(instructions.end(), std::make_move_iterator(pre.begin()),std::make_move_iterator(pre.end()));
	for(auto it = ast->children.begin(); it!= ast->children.end();++it){
		recurse(*it);
	}
	std::vector<std::unique_ptr<MachineInstruction>> post = ast->post_assemble();
	instructions.insert(instructions.end(), std::make_move_iterator(post.begin()),std::make_move_iterator(post.end()));
}
CodeGen::CodeGen(ASTNode* ast){
	recurse(ast);
	for(int i=0;i<instructions.size();i++){
		instructions[i]->print();
	}
}