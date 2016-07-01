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

void Function::printElem(){
	printf("Function: %s",name.c_str());
}