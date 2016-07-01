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
}
void ASTNode::add_child(std::shared_ptr<ASTNode> ptr){
	children.push_back(ptr);
}

void ASTNode::print(int level){
	for(int i=0;i<level;i++){
		printf("\t");
	}
	printf("ASTNode:\n");
	for(int i=0;i<children.size();i++){
		children[i]->print(level+1);
	}
}
