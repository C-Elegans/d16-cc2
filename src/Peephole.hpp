//
// Created by Michael Nolan on 7/5/16.
//

#ifndef D16_CC2_PEEPHOLE_HPP
#define D16_CC2_PEEPHOLE_HPP

#include <vector>
#include <functional>
#include "MachineInstruction.hpp"

class Peephole {
    std::vector<std::function<instruction_vec(instruction_vec)>> passes;
public:
    Peephole();
    instruction_vec run_passes(instruction_vec);
};


#endif //D16_CC2_PEEPHOLE_HPP
