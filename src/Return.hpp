//
//  Return.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Return_hpp
#define Return_hpp
#include "ASTInclude.hpp"
#include <stdio.h>
#include <string>
#include <stdio.h>

class Return : public ASTNode {


public:
	Return();
	Return(ASTNode*);
	virtual void printElem(void) override;
	virtual std::unique_ptr<MachineInstruction> assemble(void)override;
};
#endif /* Return_hpp */
