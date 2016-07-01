//
//  main.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 6/30/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include <iostream>
#include "lex.h"
#include "parser.h"
extern FILE* yyin;
extern int yydebug;
extern "C" int yyparse(void);
int main(int argc, const char * argv[]) {
	if(argc != 2){
		std::cerr << "Usage: d16-cc2 [input-file]\n";
		exit(1);
	}
	FILE* input = fopen(argv[1], "r");
	yydebug = 1;
	yyin = input;
	do {
		yyparse();
	} while (!feof(yyin));

	std::cout << "Hello, World!\n";
    return 0;
}
