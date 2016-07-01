//
//  Eval.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Eval_hpp
#define Eval_hpp
#include "ASTInclude.hpp"
#include <stdio.h>
#include <string>
#include <stdio.h>

class Eval : public ASTNode {


public:
	Eval(ASTNode*);
	virtual void printElem(void) override;
};
#endif /* Eval_hpp */
