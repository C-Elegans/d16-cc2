//
//  Assign.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Assign.hpp"
Assign::Assign(ASTNode* lval, ASTNode* rval){
	add_child(lval);
	add_child(rval);
}
void Assign::printElem(){
	printf("Assign:\n");
}
std::unique_ptr<MachineInstruction> Assign::assemble(){
	return nullptr;
}