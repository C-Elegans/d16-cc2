//
//  main.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 6/30/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include <iostream>
#include <memory>
#include "ASTNode.hpp"
#include "NumNode.hpp"
#include "Function.hpp"
#include "Operator.hpp"
#include "parser.hpp"
extern FILE* yyin;
extern int yydebug;
extern int yyparse(void);
extern ASTNode* ast;

int main(int argc, const char * argv[]) {

	
	if(argc != 2){
		std::cerr << "Usage: d16-cc2 [input-file]\n";
		exit(1);
	}
	FILE* input = fopen(argv[1], "r");
	yydebug = 0;
	yyin = input;
	do {
		yyparse();
	} while (!feof(yyin));
	ast->print(0);
	delete ast;
	
    return 0;
}
