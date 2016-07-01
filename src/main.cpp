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
void astTest(void){
	ASTNode root;
	root.add_child(std::make_shared<ASTNode>());
	root.add_child(std::make_shared<NumNode>(1));
	root.add_child(std::make_shared<Operator>(Operator_type::ADD,std::make_shared<NumNode>(3),std::make_shared<NumNode>(4)));
	root.add_child(std::make_shared<Function>("func"));
	root.print(0);
}
int main(int argc, const char * argv[]) {

	astTest();
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

	std::cout << "Hello, World!\n";
    return 0;
}
