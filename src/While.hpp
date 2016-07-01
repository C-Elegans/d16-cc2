//
//  While.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef While_hpp
#define While_hpp
#include "ASTInclude.hpp"
#include <stdio.h>
#include <string>
#include <stdio.h>

class While: public ASTNode {


public:
	While(ASTNode* condition, ASTNode* statement);
	virtual void printElem() override;
};
#endif /* While_hpp */
