#include "cpu.h"
#include "instruction.h"

CPU::CPU()
{
    for (int i = 0; i < 32; i++)
    {
        registers[i] = 0;
    }
    memory = new Memory();
}

void CPU::fetch()
{
    u32 instruction = memory->bytes[pc];
    pc++;
    decode(instruction);
}
void CPU::decode(u32 instruction_data)
{
    Instruction* instruction;
    u32 opcode = Instruction::get_opcode(instruction_data);
    u32 funct3 = 0;
    u32 funct7 = 0;
    switch (Instruction::formats_by_opcode.at(opcode))
    {
        case InstructionFormat::R:
            funct7 = Instruction::get_funct7(instruction_data);
        case InstructionFormat::I:
        case InstructionFormat::S:
        case InstructionFormat::B:
            funct3 = Instruction::get_funct3(instruction_data);
        case InstructionFormat::U:
        case InstructionFormat::J:
            break;
    }
    for (Instruction instruction_to_check : Instruction::instructions)
    {
        if ((opcode == instruction_to_check.opcode) && 
            (funct3 == instruction_to_check.funct3) && 
            (funct7 == instruction_to_check.funct7))
        {
            execute(instruction_to_check.function, instruction_data);
            break;
        }
    }
}
void CPU::execute(InstructionFunction function, u32 instruction_data)
{
    function(instruction_data, this);
}
void CPU::reset()
{
    pc = 0;
}
