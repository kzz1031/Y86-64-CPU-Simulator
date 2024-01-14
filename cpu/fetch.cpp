#include "instruction_def.h"
#include "cpu.h"
#include <stdio.h>
extern std::map<long long,std::string> comand;
extern std::string now_comand;
extern int Icode ,Ifun , ValC , ValP, now_pc;
extern int state;
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
    //printf("fetch\n");
    //printf("%d\n",pc);
    now_pc = pc;
    now_comand = comand[pc];
    ll tmp = read(pc,1);
    Ifun = ifun = tmp&(0xF); tmp>>=4;
    Icode = icode = tmp&(0xF); icode = 1<<icode;
    if(icode < 1 || icode > 2048) stat = INS;
    state = stat;
    valP = pc;
    valP++;
    //printf("pc: %lld ifun: %d icode %d\n",pc,ifun,icode);
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
    ValP = valP;
    ValC = valC;
    //printf("pc : %lld\n",valP);
    //if(needRigids) printf("rA : %d  rB : %d \n",rA,rB);
    //if(needValC) printf("valC : %lld \n",valC);
    //printf("stat : %d\n\n",stat);
    //printf("npc : %lld\n",pc);
    return;
}
