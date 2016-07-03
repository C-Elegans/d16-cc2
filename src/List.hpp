//
//  List.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include "ASTInclude.hpp"
#include <stdio.h>
#include <string>
#include <stdio.h>

class List: public ASTNode {


public:
	std::string name;
	List();
	List(std::string name);
	virtual void printElem() override;
	virtual std::unique_ptr<MachineInstruction> assemble(void)override;
};
#endif /* List_hpp */
