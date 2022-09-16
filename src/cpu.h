#pragma once
#include <iostream>
#include <map>
#include <tuple>
#include "memory.h"
#include "instruction.h"

using u32 = unsigned int;

class Instruction;
class CPU;

typedef void (*InstructionFunction) (u32 instruction_data, CPU* cpu);

class CPU
{
public:
    u32 registers[32];
    u32 pc = 0;
    Memory* memory;

    CPU();

    void fetch();
    void decode(u32 instruction);
    void execute(InstructionFunction instruction, u32 instruction_data);
    void reset();
};

