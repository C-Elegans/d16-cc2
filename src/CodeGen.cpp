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
#include <unordered_map>
#include "Peephole.hpp"
int stack_addr = 0;
std::unordered_map<std::string, int> local_addresses;
void CodeGen::recurse(ASTNode* ast, bool local){

	std::vector<std::unique_ptr<MachineInstruction>> pre = ast->pre_assemble();
	instructions.insert(instructions.end(), std::make_move_iterator(pre.begin()),std::make_move_iterator(pre.end()));
	for(auto it = ast->children.begin(); it!= ast->children.end();++it){
		if(instanceOf<Function>(ast)){
			recurse(*it, true);
		}else{
			recurse(*it, local);
		}
	}
	if(!local){
		stack_addr = 0;
		local_addresses.clear();
	}
	if(instanceOf<VarDec>(ast) && local){
		VarDec* dec = static_cast<VarDec*>(ast);
		stack_addr+= 2;
		local_addresses[dec->name] = stack_addr;
	}
	if(instanceOf<Var>(ast)){
		Var* v = static_cast<Var*>(ast);
		v->address = local_addresses[v->name];
	}
	std::vector<std::unique_ptr<MachineInstruction>> post = ast->post_assemble();
	instructions.insert(instructions.end(), std::make_move_iterator(post.begin()),std::make_move_iterator(post.end()));
}
CodeGen::CodeGen(ASTNode* ast){
	recurse(ast,false);
	for(int i=0;i<instructions.size();i++){
		instructions[i]->print();
	}
    printf("\n\n");
	Peephole p;
	instructions = std::move(p.run_passes(std::move(instructions)));
	for(int i=0;i<instructions.size();i++){
		instructions[i]->print();
	}
}