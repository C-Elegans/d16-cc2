//
//  Assign.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Assign_hpp
#define Assign_hpp
#include "ASTInclude.hpp"
#include <stdio.h>
#include <string>
#include <stdio.h>

class Assign: public ASTNode {


public:
	Assign(ASTNode* lval, ASTNode* rval);
	virtual void printElem(void) override;
	virtual std::unique_ptr<MachineInstruction> assemble(void)override;
};
#endif /* Assign_hpp */
