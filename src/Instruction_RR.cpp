//
//  Instruction_RR.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/3/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Instruction_RR.hpp"
Instruction_RR::Instruction_RR(OpType t, int _rD, int _rS){
	type = t;
	rD = _rD;
	rS = _rS;
}
Instruction_RR::Instruction_RR(OpType t, int _rD){
	type = t;
	rD = _rD;
	rS = 0;
}
void Instruction_RR::assemble(uint16_t **data){
	**data = type <<8 | ((rS<<3)&7) | (rD&7);
	++*data;
}
void Instruction_RR::print(){
	printType();
	if(type == PUSH || type == POP){
		printf(" r%d\n",rD);
	}else{
		printf(" r%d, r%d\n",rD,rS);
	}
}