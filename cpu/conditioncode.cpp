#include "cpu.h"
#include "instruction_def.h"

void cpu::ccupdate(int zf,int sf,int of)
{
    ZF = zf;
    SF = sf;
    OF = of;
}

bool cpu::isTrue(int fun){
	if(fun==CCJE)	return ZF;
	if(fun==CCJNE)	return !ZF;
	if(fun==CCJL)	return SF^OF;
	if(fun==CCJLE)	return (SF^OF)|ZF;
	if(fun==CCJG)	return (!(SF^OF))&(!ZF);
	if(fun==CCJGE)	return !(SF^OF);
	return true;
}
