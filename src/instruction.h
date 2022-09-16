#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "cpu.h"

using u32 = unsigned int;

class CPU;

typedef void (*instruction_function) (u32 instruction_data, CPU* cpu);

enum InstructionFormat
{
    R, // register
    I, // immediate
    U, // upper immediate
    S, // storejjj
    B, // branch
    J, // jump
};

class Instruction
{
public:
    static const std::map<u32, InstructionFormat> formats_by_opcode;
    static const std::vector<Instruction> instructions;

    InstructionFormat format;
    u32 opcode = 0;
    u32 funct3 = 0;
    u32 funct7 = 0;
    instruction_function function;

    Instruction(InstructionFormat format, u32 opcode, u32 funct3, u32 funct7, instruction_function function);

    static u32 get_opcode(u32 instruction_data);
    static u32 get_funct3(u32 instruction_data);
    static u32 get_funct7(u32 instruction_data);
    static u32 get_rd(u32 instruction_data);
    static u32 get_rs1(u32 instruction_data);
    static u32 get_rs2(u32 instruction_data);
    static u32 get_immediate_R(u32 instruction_data);
    static u32 get_immediate_I(u32 instruction_data);
    static u32 get_immediate_U(u32 instruction_data);
    static u32 get_immediate_S(u32 instruction_data);
    static u32 get_immediate_B(u32 instruction_data);
    static u32 get_immediate_J(u32 instruction_data);
};

