//
//  ASTNode.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "ASTNode.hpp"
#include <stdio.h>
ASTNode::ASTNode(){

}
ASTNode::ASTNode(ASTNode* child1){
	add_child(child1);
}
ASTNode::ASTNode(ASTNode* child1,ASTNode* child2){
	add_child(child1);
	add_child(child2);
}
ASTNode::ASTNode(ASTNode* child1,ASTNode* child2,ASTNode* child3){
	add_child(child1);
	add_child(child2);
	add_child(child3);
}

ASTNode::~ASTNode(){
	
	for(int i=0;i<children.size();i++){
		delete children[i];
	}
}
void ASTNode::add_child(ASTNode* ptr){
	children.push_back(ptr);
}

void ASTNode::print(int level){
	for(int i=0;i<level;i++){
		printf("    ");
	}
	this->printElem();
	for(int i=0;i<children.size();i++){
		children[i]->print(level+1);
	}
}
void ASTNode::printElem(){
	printf("ASTNode:\n");
}
void ASTNode::replace_child(ASTNode *from, ASTNode *to){
	for(int i=0;i<children.size();i++){
		if(children[i] == from){
			children[i] = to;
			delete from;
			return;
		}
	}
	for(int i=0;i<children.size();i++){
		children[i]->replace_child(from, to);
	}
}
std::unique_ptr<MachineInstruction> ASTNode::assemble(){
	return nullptr;
}

