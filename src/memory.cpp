#include "memory.h"

void Memory::read(u32 address)
{
}

void Memory::write(u32 value, u32 address)
{
    for (int i = 0; i < sizeof(u32); i++)
    {
        bytes[address + i] = (((((1 << (9)) - 1) << (8 * i)) & value) >> (8 * i));
    }
}
