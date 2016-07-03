//
//  Instruction_RI.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/3/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Instruction_RI.hpp"
Instruction_RI::Instruction_RI(OpType t, int _rD, int _immediate){
	type = t;
	rD = _rD;
	immediate = _immediate;
}
Instruction_RI::Instruction_RI(OpType t, int _immediate){
	type = t;
	rD = 0;
	immediate = _immediate;
}
void Instruction_RI::print(){
	printType();
	if(type == PUSH|| type == PUSHI){
		printf(" #%d\n",immediate);
	}else{
		printf(" r%d, #%d\n",rD,immediate);
	}
}
void Instruction_RI::assemble(uint16_t **data){
	**data = (type|0x80)<<8|rD;
	++*data;
	**data = immediate&0xffff;
	++*data;
}