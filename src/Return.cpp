//
//  Return.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Return.hpp"
Return::Return(){

}
Return::Return(ASTNode* expr){
	add_child(expr);
}
void Return::printElem(){
	printf("Return:");
}