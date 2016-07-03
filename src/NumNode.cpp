//
//  NumNode.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "NumNode.hpp"
#include "Instruction_RI.hpp"
NumNode::NumNode(int val){
	value = val;
}
NumNode::~NumNode(){

}

void NumNode::printElem(){

	printf("Number: %d\n", value);
	//Will never have children
}
std::vector<std::unique_ptr<MachineInstruction>> NumNode::post_assemble(void){
	std::vector<std::unique_ptr<MachineInstruction>> v;
	v.push_back(std::make_unique<Instruction_RI>(PUSH,value));
	return v;
}