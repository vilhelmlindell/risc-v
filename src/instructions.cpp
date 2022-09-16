#include "instructions.h"
#include "cpu.h"
#include "instruction.h"

void instruction_add(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rs2 = Instruction::get_rs2(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    cpu->registers[rd] = cpu->registers[rs1] + cpu->registers[rs2];
}
void instruction_sub(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rs2 = Instruction::get_rs2(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    cpu->registers[rd] = cpu->registers[rs1] - cpu->registers[rs2];
}
void instruction_xor(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rs2 = Instruction::get_rs2(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    cpu->registers[rd] = cpu->registers[rs1] ^ cpu->registers[rs2];
}
void instruction_or(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rs2 = Instruction::get_rs2(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    cpu->registers[rd] = cpu->registers[rs1] | cpu->registers[rs2];
}
void instruction_and(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rs2 = Instruction::get_rs2(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    cpu->registers[rd] = cpu->registers[rs1] & cpu->registers[rs2];
}
void instruction_sll(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rs2 = Instruction::get_rs2(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    cpu->registers[rd] = cpu->registers[rs1] << cpu->registers[rs2];
}
void instruction_srl(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rs2 = Instruction::get_rs2(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    cpu->registers[rd] = cpu->registers[rs1] >> cpu->registers[rs2];
}
void instruction_sra(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rs2 = Instruction::get_rs2(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    int a = (signed)cpu->registers[rs1];
    int b = (signed)cpu->registers[rs2];
    if (a < 0 && b > 0)
        cpu->registers[rd] = a >> b | ~(~0U >> b);
    else
        cpu->registers[rd] = a >> b;
}
void instruction_slt(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rs2 = Instruction::get_rs2(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    cpu->registers[rd] = (signed)cpu->registers[rs1] < (signed)cpu->registers[rs2] ? 1 : 0;
}
void instruction_sltu(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rs2 = Instruction::get_rs2(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    cpu->registers[rd] = cpu->registers[rs1] < cpu->registers[rs2] ? 1 : 0;
}
void instruction_addi(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    u32 immediate = Instruction::get_immediate_I(instruction_data);
    cpu->registers[rd] = cpu->registers[rs1] + immediate;
}
void instruction_xori(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    u32 immediate = Instruction::get_immediate_I(instruction_data);
    cpu->registers[rd] = cpu->registers[rs1] ^ immediate;
}
void instruction_ori(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    u32 immediate = Instruction::get_immediate_I(instruction_data);
    cpu->registers[rd] = cpu->registers[rs1] | immediate;
}
void instruction_andi(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    u32 immediate = Instruction::get_immediate_I(instruction_data);
    cpu->registers[rd] = cpu->registers[rs1] & immediate;
}
void instruction_slli(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    u32 immediate = Instruction::get_immediate_I(instruction_data);
    cpu->registers[rd] = cpu->registers[rs1] << (((1 << 6) - 1) & immediate);
}
void instruction_srli(u32 instruction_data, CPU* cpu)
{
    u32 rs1 = Instruction::get_rs1(instruction_data);
    u32 rd = Instruction::get_rd(instruction_data);
    u32 immediate = Instruction::get_immediate_I(instruction_data);
    cpu->registers[rd] = cpu->registers[rs1] >> (((1 << 6) - 1) & immediate);
}

