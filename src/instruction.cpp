#include "instruction.h"
#include "instructions.h"

using u64 = unsigned long;

const std::map<u32, InstructionFormat> Instruction::formats_by_opcode = 
{
    { 0b0110011, InstructionFormat::R },
    { 0b0010011, InstructionFormat::I },
    { 0b0000011, InstructionFormat::I },
    { 0b1100111, InstructionFormat::I },
    { 0b1110011, InstructionFormat::I },
    { 0b0110111, InstructionFormat::U },
    { 0b0010111, InstructionFormat::U },
    { 0b0100011, InstructionFormat::S },
    { 0b1100011, InstructionFormat::B },
    { 0b1101111, InstructionFormat::J },
};

const std::vector<Instruction> Instruction::instructions = 
{
    Instruction(InstructionFormat::R, 0b0110011, 0x0, 0x00, instruction_add)
};

Instruction::Instruction(InstructionFormat format, u32 opcode, u32 funct3, u32 funct7, instruction_function function) 
{
    this->format = format;
    this->opcode = opcode;
    this->funct3 = funct3;
    this->funct7 = funct7;
    this->function = function;
}

u32 Instruction::get_opcode(u32 instruction_data)
{
    return ((1 << 7) - 1) & instruction_data;
}
u32 Instruction::get_funct3(u32 instruction_data)
{
    return ((((1 << 4) - 1) << 12) & instruction_data) >> 12; 
}
u32 Instruction::get_funct7(u32 instruction_data)
{
    return ((((1U << 8) - 1) << 25) & instruction_data) >> 25; 
}
u32 Instruction::get_rd(u32 instruction_data)
{
    return ((((1 << 6) - 1) << 7) & instruction_data) >> 7;
}
u32 Instruction::get_rs1(u32 instruction_data)
{
    return ((((1 << 6) - 1) << 15) & instruction_data) >> 15;
}
u32 Instruction::get_rs2(u32 instruction_data)
{
    return ((((1 << 6) - 1) << 20) & instruction_data) >> 20;
}
u32 Instruction::get_immediate_I(u32 instruction_data)
{
    return ((((1U << 13) - 1) << 20) & instruction_data) >> 20;
}
u32 Instruction::get_immediate_U(u32 instruction_data)
{
    return ((((1U << 21) - 1) << 12) & instruction_data) >> 12;
}
u32 Instruction::get_immediate_S(u32 instruction_data)
{
    return (((((1 << 6) - 1) << 7) & instruction_data) >> 7) ^ 
           (((((1U << 8) - 1) << 25) & instruction_data) >> 20);
}
u32 Instruction::get_immediate_B(u32 instruction_data)
{
    return (((((1 << 5) - 1) << 8) & instruction_data) >> 8) ^ 
           (((((1 << 7) - 1) << 25) & instruction_data) >> 21) ^
           (((1 << 7) & instruction_data) << 3) ^
           (((1 << 31) & instruction_data) >> 20);
}
u32 Instruction::get_immediate_J(u32 instruction_data)
{
    return (((((1 << 11) - 1) << 21) & instruction_data) >> 21) ^ 
           (((1 << 20) & instruction_data) >> 10) ^
           (((((1 << 9) - 1) << 12) & instruction_data) >> 1) ^
           (((1 << 31) & instruction_data) >> 12);
}



