//
//  Function.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef Function_hpp
#define Function_hpp
#include "ASTNode.hpp"
#include <string>
#include <stdio.h>

class Function : public ASTNode {
	std::string name;

public:
	Function(std::string name);
	virtual void print(int level) override;
};

#endif /* Function_hpp */
