//
//  CodeGen.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/3/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef CodeGen_hpp
#define CodeGen_hpp

#include <stdio.h>
#include "ASTInclude.hpp"
#include "MachineInstruction.hpp"

class CodeGen {
	std::vector<std::unique_ptr<MachineInstruction>> instructions;
	void recurse(ASTNode* ast);
public:
	CodeGen(ASTNode* ast);
	void assemble(uint16_t* data);
};
#endif /* CodeGen_hpp */
