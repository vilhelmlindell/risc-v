#pragma once

using u32 = unsigned int;
using byte = unsigned char;

class Memory
{
public:
    byte bytes[1024];

    void read(u32 address);
    void write(u32 value, u32 address);
};
