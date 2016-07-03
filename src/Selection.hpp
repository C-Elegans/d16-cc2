//
//  Selection.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Selection_hpp
#define Selection_hpp
#include "ASTInclude.hpp"
#include <stdio.h>
#include <string>
#include <stdio.h>

class Selection: public ASTNode {


public:
	Selection(ASTNode* condition, ASTNode* statement);//if (expression) { expression }
	Selection(ASTNode* condition, ASTNode* statement, ASTNode* else_statement);//if (expression) {expression} else {expression}
	virtual void printElem() override;
	virtual std::unique_ptr<MachineInstruction> assemble(void)override;
};
#endif /* Selection_hpp */
