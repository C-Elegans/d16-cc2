//
//  ExpressionSimplifier.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/2/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef ExpressionSimplifier_hpp
#define ExpressionSimplifier_hpp
#include "OptimizePass.hpp"
#include <stdio.h>

class ExpressionSimplifier: public OptimizePass {


public:
	ExpressionSimplifier();
	virtual void runPass(ASTNode* ast);
};

#endif /* ExpressionSimplifier_hpp */
