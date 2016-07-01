//
//  NumNode.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "NumNode.hpp"
NumNode::NumNode(int val){
	value = val;
}
NumNode::~NumNode(){

}

void NumNode::print(int level){
	for(int i=0;i<level;i++){
		printf("\t");
	}
	printf("Number: %d\n", value);
	//Will never have children
}