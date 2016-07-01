//
//  Var.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Var.hpp"
Var::Var(std::string _name){
	name = _name;
	isArray = false;
}
Var::Var(std::string _name, ASTNode* addr){
	name = _name;
	isArray = true;
	add_child(addr);
}
void Var::printElem(){
	if(isArray){
		printf("Var: %s[]\n",name.c_str());
	}else{
		printf("Var: %s\n",name.c_str());
	}
}