//
//  Call.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Call.hpp"
Call::Call(std::string name, ASTNode* args){
	f_name = name;
	add_child(args);
}
void Call::printElem(){
	printf("%s()\n",f_name.c_str());
}