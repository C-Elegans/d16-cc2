//
//  Function.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Function.hpp"


Function::Function(std::string _name){
	name = _name;
}

void Function::print(int level){
	for(int i=0;i<level;i++){
		printf("\t");
	}
	printf("Function: %s\n",name.c_str());
	for(int i=0;i<children.size();i++){
		children[i]->print(level+1);
	}
}