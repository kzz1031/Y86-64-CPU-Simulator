#include "cpu.h"
#include "instruction_def.h"
extern long long ValA, ValB, DstE, DstM;
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
    ValA = valA = reg[d_srcA()];
    ValB = valB = reg[d_srcB()];
    DstE = dstE = d_dstE();
    DstM = dstM = d_dstM();
    //printf("decode \n");
    //printf("icode : %d\n ",icode);
    //printf("srcA : %llx  srcB : %llx  dstE : %llx  dstM : %llx\n",d_srcA(),d_srcA(),d_dstE(),d_dstM());
    //printf("stat : %d\n\n",stat);
}
