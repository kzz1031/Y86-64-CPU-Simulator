#include "instruction_def.h"
#include "cpu.h"
#include <stdio.h>
bool cpu::Need_regids(ll icode)
{
    return icode&(RRMOVQ|OPQ|PUSHQ|POPQ|IRMOVQ|RMMOVQ|MRMOVQ);
}
bool cpu::Need_valC(ll icode)
{
    return icode&(IRMOVQ|RMMOVQ|MRMOVQ|JXX|CALL);
}

void cpu::fetch()
{
    ll tmp = read(pc,1);
    ifun = tmp&(0xF); tmp>>=4;
    icode = tmp&(0xF); icode = 1<<icode;
    if(icode < 1 || icode > 2048) stat = INS;

    valP = pc;
    valP++;
    bool needRigids = Need_regids(icode);
    bool needValC = Need_valC(icode);
    rA = rB = RNONE;
    if(needRigids)
    {
        tmp = read(valP,1);
        rB = tmp & 0xF; tmp >>= 4;
        rA = tmp & 0xF;
        valP++;
    }

    valC = 0;
    if(needValC)
    {
        tmp = read(valP,8);
        valC = tmp;
        valP += 8;
    }
    return;
}