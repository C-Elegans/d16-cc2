//
//  Function.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Function_hpp
#define Function_hpp
#include "ASTNode.hpp"
#include <string>
#include <stdio.h>
#include "type.h"
class Function : public ASTNode {


public:
	std::string name;
	type_t type;
	Function(type_t type, std::string name, ASTNode* params, ASTNode* body);
	virtual void printElem(void) override;
	virtual std::unique_ptr<MachineInstruction> assemble(void)override;
	};

#endif /* Function_hpp */
