//
//  While.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "While.hpp"
While::While(ASTNode* condition, ASTNode* statement){
	add_child(condition);
	add_child(statement);
}
void While::printElem(){
	printf("While:\n");
}