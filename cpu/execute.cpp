#include "cpu.h"
#include "instruction_def.h"
extern long long ValE;
extern int is_opq;
ll cpu::aluA(){
    if(icode&(RRMOVQ|OPQ)) return valA;
    if(icode&(IRMOVQ|RMMOVQ|MRMOVQ)) return valC;
    if(icode&(CALL|PUSHQ)) return -8;
    if(icode&(RET|POPQ)) return 8;
    return 0;
}

ll cpu::aluB(){
    if(icode&(RMMOVQ|MRMOVQ|OPQ|CALL|PUSHQ|RET|POPQ)) return valB;
    if(icode&(RRMOVQ|IRMOVQ)) return 0;
    return 0;
}

ll cpu::alufun(){
    if(icode&OPQ) return ifun;
    return ALUADD;
}

ll cpu::e_valE(){
    ll fun=alufun();
    ll a=aluA(),b=aluB();
    ll e=0;
    if(fun==ALUADD)	{e=a+b;}
	if(fun==ALUSUB)	{e=b-a;}
	if(fun==ALUAND) {e=a&b;}
	if(fun==ALUXOR)	{e=a^b;}
    //printf("a:%lld  fun:%d  e:%lld ",a,ifun,e);
	return e;
}

ll cpu::e_valE_setcc(){
    ll fun=alufun();
    ll a=aluA(),b=aluB();
    ll e=0;
    if(fun==ALUADD)	{e=a+b;ccupdate(e==0,e<0,(a>0&&b>0&&e<0)||(a<0&&b<0&&e>0));}
	if(fun==ALUSUB)	{e=b-a;ccupdate(e==0,e<0,(a>0&&b<0&&e>0)||(a<0&&b>0&&e<0));}
	if(fun==ALUAND) {e=a&b;ccupdate(e==0,e<0,0);}
	if(fun==ALUXOR)	{e=a^b;ccupdate(e==0,e<0,0);}
	return e;
}

void cpu::execute()
{
    
    if(icode & OPQ)
    {
        valE = e_valE_setcc();
        is_opq = 1;
    }
    else
    {
        valE = e_valE();
        is_opq = 0;
    }
    ValE = valE;
    //printf("execute\n");
    //printf("stat : %d\n\n",stat);
}
