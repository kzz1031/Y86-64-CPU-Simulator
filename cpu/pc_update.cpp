#include "cpu.h"
#include "instruction_def.h"
extern long long now_pc;
extern std::map<long long,std::string> comand;
extern std::string now_comand;
void cpu::update_pc()
{
    //printf("pc update\n");
    if(stat != AOK) return;
    else if(icode&CALL)  pc = valC;
    else if(icode&RET)  pc = valM;
    else if(icode&JXX)
    {
        cnd = 0;
        if(isTrue(ifun)) pc = valC;
        else pc = valP;
    }
    else pc = valP;
    now_pc = pc;
    now_comand = comand[pc];
    //printf("new pc: %lld\n\n\n",pc);
}
