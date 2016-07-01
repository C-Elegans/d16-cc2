//
//  VarDec.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef VarDec_hpp
#define VarDec_hpp
#include "ASTInclude.hpp"
#include <stdio.h>
#include <string>
#include <stdio.h>
enum class type_t{T_INT, T_VOID};
class VarDec: public ASTNode {


public:
	type_t vartype;
	std::string name;
	VarDec(std::string _name, type_t type);
	VarDec(std::string _name, type_t type, ASTNode* size);
	virtual void printElem() override;
};
#endif /* VarDec_hpp */
