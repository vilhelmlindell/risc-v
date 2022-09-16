#include <cstdlib>
#include <gtest/gtest.h>
#include "cpu.h"
#include "instructions.h"

TEST(InstructionTest, IsAddInstructionWorking)
{
    CPU* cpu = new CPU();
    cpu->registers[1] = 13;
    cpu->registers[2] = 5;
    instruction_add(0b00000000001000001000000110110011, cpu);
    EXPECT_EQ(18, cpu->registers[3]);
}
TEST(InstructionTest, IsSubInstructionWorking)
{
    CPU* cpu = new CPU();
    cpu->registers[1] = 62;
    cpu->registers[2] = 8;
    instruction_sub(0b00000000001000001000000110110011, cpu);
    EXPECT_EQ(54, cpu->registers[3]);
}
TEST(InstructionTest, IsXorInstructionWorking)
{
    CPU* cpu = new CPU();
    cpu->registers[1] = 23;
    cpu->registers[2] = 53;
    instruction_xor(0b00000000001000001000000110110011, cpu);
    EXPECT_EQ(34, cpu->registers[3]);
}
