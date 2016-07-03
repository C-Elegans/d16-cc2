//
//  Instruction_Mem.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/3/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "Instruction_Mem.hpp"
Instruction_Mem::Instruction_Mem(OpType t, int _rD, int _rS){
	type = t;
	rD = _rD;
	rS = _rS;
	imm = false;
}
Instruction_Mem::Instruction_Mem(OpType t, int _rD, int _rS, int _imm, bool _displacement){
	type = t;
	imm = true;
	if(t == LD){
		rD = _rD;
		rS = _rS;
		immediate = _imm;
	}else{
		rS = _rD;
		rD = _rS;
		immediate = _imm;
	}
	displacement =_displacement;
}
void Instruction_Mem::print(){
	printType();
	char immediate_str[16];
	if(displacement){
		snprintf(immediate_str, sizeof(immediate_str), "r%d+0x%04x",rS,immediate);
	}else{
		snprintf(immediate_str, sizeof(immediate_str), "0x%04x",immediate);
	}
	if(type == LD){
		if(imm){
			printf(" r%d,[%s]\n",rD,immediate_str);
		}else{
			printf(" r%d,[r%d]\n",rD,rS);
		}
	}else{
		if(imm){
			printf(" [%s],r%d\n",immediate_str,rD);
		}else{
			printf(" [r%d],%d\n",rD,rS);
		}
	}
}
void Instruction_Mem::assemble(uint16_t **data){

}