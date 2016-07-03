//
//  Function.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Function.hpp"


Function::Function(type_t _type, std::string _name, ASTNode* params, ASTNode* body){
	name = _name;
	type = _type;
	add_child(params);
	add_child(body);
}

void Function::printElem(){
	printf("Function: %s\n",name.c_str());
}