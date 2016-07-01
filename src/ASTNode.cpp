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
		printf("\t");
	}
	this->printElem();
	for(int i=0;i<children.size();i++){
		children[i]->print(level+1);
	}
}
void ASTNode::printElem(){
	printf("ASTNode:\n");
}
