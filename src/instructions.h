#pragma once
#include "instruction.h"
#include "cpu.h"

void instruction_add(u32 instruction_data, CPU* cpu);
void instruction_sub(u32 instruction_data, CPU* cpu);
void instruction_xor(u32 instruction_data, CPU* cpu);
void instruction_or(u32 instruction_data, CPU* cpu);
void instruction_and(u32 instruction_data, CPU* cpu);
void instruction_sll(u32 instruction_data, CPU* cpu);
void instruction_srl(u32 instruction_data, CPU* cpu);
void instruction_sra(u32 instruction_data, CPU* cpu);
void instruction_slt(u32 instruction_data, CPU* cpu);
void instruction_sltu(u32 instruction_data, CPU* cpu);
void instruction_addi(u32 instruction_data, CPU* cpu);
