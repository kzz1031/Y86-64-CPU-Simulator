#include "cpu.h"
#include "instruction_def.h"

ll cpu::d_srcA(){
    if(icode&(RRMOVQ|RMMOVQ|OPQ|PUSHQ)) return rA;
    if(icode&(POPQ|RET)) return RSP;
    return RNONE;
}

ll cpu::d_srcB(){
    if(icode&(OPQ|RMMOVQ|MRMOVQ)) return rB;
    if(icode&(PUSHQ|POPQ|CALL|RET)) return RSP;
    return RNONE;
}

ll cpu::d_dstE(){
    if(icode&(RRMOVQ|IRMOVQ|OPQ)) return rB;
    if(icode&(PUSHQ|POPQ|CALL|RET)) return RSP;
    return RNONE;
}

ll cpu::d_dstM(){
    if(icode&(MRMOVQ|POPQ)) return rA;
    return RNONE;
}

void cpu::decode()
{
    valA = reg[d_srcA()];
    valB = reg[d_srcB()];
    dstE = d_dstE();
    dstM = d_dstM();
}