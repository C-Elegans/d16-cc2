//
//  Param.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Param_hpp
#define Param_hpp
#include "ASTInclude.hpp"

#include <stdio.h>
#include <string>
#include <stdio.h>
#include "type.h"
class Param: public ASTNode {


public:
	type_t type;
	std::string name;
	bool array;
	Param(std::string _name, type_t type, bool array);

	virtual void printElem() override;
	virtual std::unique_ptr<MachineInstruction> assemble(void)override;
};
#endif /* Param_hpp */
