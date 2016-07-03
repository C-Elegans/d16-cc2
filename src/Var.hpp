//
//  Var.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Var_hpp
#define Var_hpp
#include "ASTInclude.hpp"
#include <stdio.h>
#include <string>
class Var : public ASTNode {


public:
	std::string name;
	bool isArray;
	Var(std::string name);
	Var(std::string name,ASTNode* addr);
	virtual void printElem(void) override;
	virtual std::unique_ptr<MachineInstruction> assemble(void)override;
};

#endif /* Var_hpp */
