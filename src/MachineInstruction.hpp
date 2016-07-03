//
//  MachineInstruction.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/3/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef MachineInstruction_hpp
#define MachineInstruction_hpp
#include <cstdint>
#include <stdio.h>
typedef enum _Op_Type{
	NOP=0,
	ADD,
	SUB,
	PUSH,
	POP,
	MOVB,
	MOV=0x0D,
	AND,
	OR,
	XOR,
	NOT,
	NEG,
	LD,
	ST,
	CMP,
	JMP,
	CALL,
	SPEC,
	SHL,
	SHR,
	ROL,
	RCL,
	LDCP,
	STCP,
	ADC,
	SBB,

	ADDI=0x81,
	SUBI=0x82,
	PUSHI=0x83,
	MOVI=0x8D,
	ANDI=0x8e,
	ORI=0x8f,
	XORI=0x90,
	LDI=0x93,
	STI=0x94,
	CMPI=0x95,
	JMPI=0x96,
	CALLI=0x97,
	SHLI=0x99,
	SHRI=0x9a,
	ROLI=0x9b,
	RCLI=0x9c,
	ADCI=0x9f,
	SBBI=0xA0
} OpType;
class MachineInstruction {
protected:
	OpType type;

public:
	
	virtual void assemble(uint16_t** data) = 0;
	virtual void print() = 0;
	void printType();
};
#endif /* MachineInstruction_hpp */
