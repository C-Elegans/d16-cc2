//
//  VarDec.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "VarDec.hpp"
static const char* type_strings[] = {"int","void"};
VarDec::VarDec(std::string _name, type_t type){
	name = _name;
	vartype = type;
}
VarDec::VarDec(std::string _name, type_t type, ASTNode* size){
	name = _name;
	vartype = type;
	add_child(size);
}
void VarDec::printElem(){
	printf("Vardec: %s %s\n",type_strings[static_cast<int>(vartype)],name.c_str());
}