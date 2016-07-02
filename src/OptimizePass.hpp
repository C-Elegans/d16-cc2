//
//  OptimizePass.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/2/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef OptimizePass_hpp
#define OptimizePass_hpp
#include "ASTNode.hpp"
#include <stdio.h>

class OptimizePass {


public:
	
	virtual void runPass(ASTNode* ast) = 0;
};
#endif /* OptimizePass_hpp */
