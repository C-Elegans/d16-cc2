//
//  Operator.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Operator_hpp
#define Operator_hpp
#include "ASTNode.hpp"
#include <stdio.h>

enum class Operator_type{ADD,SUBTRACT,MULTIPLY,DIVIDE,CMP_EQ,CMP_NE,CMP_GT,CMP_LT,CMP_GE,CMP_LE};
class Operator : public ASTNode{


public:
	Operator_type type;
	Operator(Operator_type type,AST_ptr child1, AST_ptr child2);
	virtual void print(int level) override;
};
#endif /* Operator_hpp */
