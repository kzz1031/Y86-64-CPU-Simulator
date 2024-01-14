#include "cpu.h"
#include "instruction_def.h"

 void cpu::reg_write(int addr,ll val)
 {
    if(addr<0 || addr > 15) stat = ADR;
    reg[addr] = val;
 }

void cpu::writeback()
{
    //printf("writeback\n");
    //printf("dstE : %lld  valE : %lld  dstM : %lld  valM : %lld\n",dstE,valE,dstM,valM);
    if(icode & RRMOVQ)
        if(!isTrue(ifun)) return ;
    reg_write(dstE,valE);
    reg_write(dstM,valM);
    if(icode == HALT) stat = HLT;
}