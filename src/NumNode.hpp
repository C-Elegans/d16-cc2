//
//  NumNode.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef NumNode_hpp
#define NumNode_hpp
#include "ASTNode.hpp"
#include <stdio.h>

class NumNode: public ASTNode {


public:
	int value;
	NumNode(int val);
	~NumNode();
	virtual void printElem(void) override;
};
#endif /* NumNode_hpp */
