#include "cpu.h"
#include "instruction_def.h"

bool cpu::mem_read()
{
    return icode&(MRMOVQ|POPQ|RET);
}

bool cpu::mem_write()
{
    return icode&(RMMOVQ|PUSHQ|CALL);
}

ll cpu::mem_addr()
{
    if(icode&(RMMOVQ|PUSHQ|CALL|MRMOVQ)) return valE;
    if(icode&(POPQ|RET)) return valA;
    return -1;
}

void cpu::_Memory()
{

    if(mem_read())
    {
        valM = read(mem_addr(),8);
    } 
    if(mem_write())
    {
        if(icode & CALL) write(mem_addr(),valP);
        else write(mem_addr(),valA);
    } 
}
