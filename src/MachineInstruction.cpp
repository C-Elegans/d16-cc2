//
//  MachineInstruction.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/3/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "MachineInstruction.hpp"
static const char* opcodes_str[] = {
	"nop",
	"add",
	"sub",
	"push",
	"pop",
	"mov",
	"and",
	"or",
	"xor",
	"not",
	"neg",
	"ld",
	"st",
	"cmp",
	"jmp",
	"call",
	"spec",
	"shl",
	"shr",
	"rol",
	"rcl",
	"ldcp",
	"stcp"
};
void MachineInstruction::printType(){
	printf("%s",opcodes_str[type&0x7f]);
}
