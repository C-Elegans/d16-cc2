//
//  Call.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Call_hpp
#define Call_hpp

#include "ASTInclude.hpp"
#include <stdio.h>
#include <string>
#include <stdio.h>

class Call: public ASTNode {


public:
	std::string f_name;
	Call(std::string, ASTNode*);
	virtual void printElem() override;
	virtual std::unique_ptr<MachineInstruction> assemble(void)override;
};
#endif /* Call_hpp */
