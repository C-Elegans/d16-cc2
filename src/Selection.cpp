//
//  Selection.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Selection.hpp"
Selection::Selection(ASTNode* condition, ASTNode* statement){
	add_child(condition);
	add_child(statement);
}
Selection::Selection(ASTNode* condition, ASTNode* statement, ASTNode* else_statement){
	add_child(condition);
	add_child(statement);
	add_child(else_statement);
}
void Selection::printElem(){
	printf("If: \n");
}