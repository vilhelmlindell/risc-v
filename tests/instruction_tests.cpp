#include <gtest/gtest.h>
#include "instruction.h"

TEST(InstructionParseTest, OpcodeIsCorrectBits)
{
    EXPECT_EQ(0b0110011, Instruction::get_opcode(0b00000000000000000000000000110011));
}
TEST(InstructionParseTest, Funct3IsCorrectBits)
{
    EXPECT_EQ(0b111, Instruction::get_funct3(0b00000000000000000111000000000000));
}
TEST(InstructionParseTest, Funct7IsCorrectBits)
{
    EXPECT_EQ(0b1101011, Instruction::get_funct7(0b11010110000000000000000000000000));
}
TEST(InstructionParseTest, RdIsCorrectBits)
{
    EXPECT_EQ(0b10011, Instruction::get_rd(0b00000000000000000100110000000));
}
TEST(InstructionParseTest, Rs1IsCorrectBits)
{
    EXPECT_EQ(0b01011, Instruction::get_rs1(0b00000000000001011000000000000000));
}
TEST(InstructionParseTest, Rs2IsCorrectBits)
{
    EXPECT_EQ(0b11010, Instruction::get_rs2(0b00000001101000000000000000000000));
}
TEST(InstructionParseTest, ImmediateIIsCorrectBits)
{
    EXPECT_EQ(0b100110011101, Instruction::get_immediate_I(0b10011001110100000000000000000000));
}
TEST(InstructionParseTest, ImmediateUIsCorrectBits)
{
    EXPECT_EQ(0b01011010101100010001, Instruction::get_immediate_U(0b01011010101100010001000000000000));
}
TEST(InstructionParseTest, ImmediateSIsCorrectBits)
{
    EXPECT_EQ(0b101101001001, Instruction::get_immediate_S(0b10110100000000000000010010000000));
}
TEST(InstructionParseTest, ImmediateBIsCorrectBits)
{
    EXPECT_EQ(0b101110011011, Instruction::get_immediate_B(0b11110010000000000000101100000000));
}
TEST(InstructionParseTest, ImmediateJIsCorrectBits)
{
    EXPECT_EQ(0b10110010100010011001, Instruction::get_immediate_J(0b10010011001001101000000000000000));
}
