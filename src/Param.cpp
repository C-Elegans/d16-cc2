//
//  Param.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Param.hpp"
static const char* type_strings[] = {"int","void"};
Param::Param(std::string _name, type_t _type, bool _array){
	name = _name;
	type = _type;
	array = _array;
}
void Param::printElem(){
	if(array){
		printf("%s %s[]\n",type_strings[static_cast<int>(type)],name.c_str());
	}
	else{
		printf("%s %s\n",type_strings[static_cast<int>(type)],name.c_str());
	}
}
std::unique_ptr<MachineInstruction> Param::assemble(){
	return nullptr;
}