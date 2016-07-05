//
// Created by Michael Nolan on 7/5/16.
//

#include "Peephole.hpp"
#include "ASTInclude.hpp"
#include "Instruction_RI.hpp"
#include "Instruction_RR.hpp"

Peephole::Peephole() {
/*
 * converts:
 *      push r0
 *      pop r0
 * into:
 *      (nothing)
 *
 */
    passes.push_back([](instruction_vec instructions) {
        for (int i = 0; i < instructions.size() - 1; i++) {
            if (instructions[i]->type == PUSH && instructions[i + 1]->type == POP) {
                if (instanceOf<Instruction_RR>(&(*instructions[i]))) {
                    if (dynamic_cast<Instruction_RR &>(*instructions[i]).rD ==
                        dynamic_cast<Instruction_RR &>(*instructions[i + 1]).rD) {
                        instructions.erase(instructions.begin() + i, instructions.begin() + i + 2);
                    }
                }
            }
        }
        return instructions;
    });
    /*
     * converts:
     *      push #1
     *      pop r0
     * into:
     *      mov r0, #1
     */
    passes.push_back([](instruction_vec instructions) {
        for (int i = 0; i < instructions.size() - 1; i++) {
            if (instructions[i]->type == PUSH && instructions[i + 1]->type == POP) {
                if (instanceOf<Instruction_RI>(&(*instructions[i]))) {


                    std::unique_ptr<Instruction_RI> inst = std::make_unique<Instruction_RI>(MOV,
                                                                                            dynamic_cast<Instruction_RR &>(*instructions[
                                                                                                    i + 1]).rD,
                                                                                            dynamic_cast<Instruction_RI &>(*instructions[i]).immediate
                    );
                    instructions.erase(instructions.begin() + i, instructions.begin() + i + 2);
                    instructions.insert(instructions.begin() + i, std::move(inst));
                }
            }
        }
        return instructions;
    });

    /*
     * converts:
     *      push r0
     *      mov r1,#1
     *      pop r0
     * into:
     *      mov r1,#1
     */
    passes.push_back([](instruction_vec instructions) {
        for (int i = 0; i < instructions.size() - 2; i++) {
            if (instructions[i]->type == PUSH && instructions[i + 2]->type == POP) {
                if (instanceOf<Instruction_RR>(&(*instructions[i]))) {
                    int rd = dynamic_cast<Instruction_RR &>(*instructions[i]).rD;
                    if (rd == dynamic_cast<Instruction_RR &>(*instructions[i + 2]).rD) {
                        if ((instanceOf<Instruction_RR>(&(*instructions[i + 1])) &&
                             rd != dynamic_cast<Instruction_RR &>(*instructions[i + 1]).rD) ||
                            (instanceOf<Instruction_RI>(&(*instructions[i + 1])) &&
                             rd != dynamic_cast<Instruction_RI &>(*instructions[i + 1]).rD)) {
                            instructions.erase(instructions.begin() + i + 2);
                            instructions.erase(instructions.begin() + i);

                        }


                    }

                }
            }
        }
        return instructions;
    });
    /*
     * converts:
     *      mov r1,#1
     *      (op) r0,r1
     * into:
     *      (op) r0,#1
     */
    passes.push_back([](instruction_vec instructions){
        for(int i=0;i<instructions.size()-1;i++){
            if(instructions[i]->type == MOV){
                if(instanceOf<Instruction_RI>(&(*instructions[i])) && instanceOf<Instruction_RR>(&(*instructions[i+1]))){
                    int rd_1 = static_cast<Instruction_RI&>(*instructions[i]).rD;
                    int imm = static_cast<Instruction_RI&>(*instructions[i]).immediate;
                    int rs_2 = static_cast<Instruction_RR&>(*instructions[i+1]).rS;
                    int rd_2 = static_cast<Instruction_RR&>(*instructions[i+1]).rD;
                    OpType type = instructions[i+1]->type;
                    if(rd_1 == rs_2){
                        instructions.erase(instructions.begin()+i, instructions.begin()+i+2);
                        instructions.insert(instructions.begin()+i,std::make_unique<Instruction_RI>(type,rd_2, imm));
                    }
                }
            }
        }
        return instructions;
    });

}

instruction_vec Peephole::run_passes(instruction_vec instructions) {
    for (int i = 0; i < passes.size(); i++) {
        instructions = std::move(passes[i](std::move(instructions)));
    }
    return instructions;
}