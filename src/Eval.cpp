//
//  Eval.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Eval.hpp"
Eval::Eval(ASTNode* a){
	add_child(a);
}
void Eval::printElem(){
	printf("Eval:\n");
}