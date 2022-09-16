#include <gtest/gtest.h>
#include "cpu.h"
#include "instructions.h"

int main(int argc, char* argv[])
{
    CPU* cpu = new CPU();
    cpu->registers[1] = 5;
    cpu->registers[2] = 3;
    instruction_add(0b00000000001000001000000110110011, cpu);
    std::cout << cpu->registers[3] << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

