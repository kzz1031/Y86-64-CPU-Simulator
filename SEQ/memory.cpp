#include "cpu.h"
#include<stdio.h>
bool cpu::writeByte(ll addr,int val)
{
    memo[addr] = val;
    return true;
}

bool cpu::write(ll addr, ll val)
{
    if(addr < 0) stat = ADR;
    max_addr = std::max(max_addr,addr);
    writeByte(addr, val & 0xFF);
    val >>= 8;
    writeByte(addr + 1, val & 0xFF);
    val >>= 8;
    writeByte(addr + 2, val & 0xFF);
    val >>= 8;
    writeByte(addr + 3, val & 0xFF);
    val >>= 8;
    writeByte(addr + 4, val & 0xFF);
    val >>= 8;
    writeByte(addr + 5, val & 0xFF);
    val >>= 8;
    writeByte(addr + 6, val & 0xFF);
    val >>= 8;
    writeByte(addr + 7, val & 0xFF);
    return 1; 
}

ll cpu::read(ll addr, int len)
{
    if(addr < 0) stat = ADR;
    if(addr + len - 1 < addr)
    {
        memoErro = 1;
        return 0;
    }
    if(len == 1) return readByte(addr);
    else if(len == 8) return (readByte(addr+7)<<56)|(readByte(addr+6)<<48)|(readByte(addr+5)<<40)|(readByte(addr+4)<<32)
                           |(readByte(addr+3)<<24)|(readByte(addr+2)<<16)|(readByte(addr+1)<<8)|readByte(addr);//--------
    return 1;
}

ll cpu::readByte(ll addr)
{
    if(!memo.count(addr)) return 0;
    else return memo[addr];
}
