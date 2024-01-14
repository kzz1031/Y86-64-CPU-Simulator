#include "cpu.h"
#include "instruction_def.h"

void cpu::update_pc()
{
    if(stat != AOK) pc = pc;
    else if(icode&CALL)  pc = valC;
    else if(icode&RET)  pc = valM;
    else if(icode&JXX)
    {
        cnd = 0;
        if(isTrue(ifun)) pc = valC;
        else pc = valP;
    }
    else pc = valP;
}