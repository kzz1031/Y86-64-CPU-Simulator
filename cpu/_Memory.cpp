#include "cpu.h"
#include "instruction_def.h"
#include <QDebug>
extern int read_write;
extern ll addr_memo,val_memo;
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
    //printf("Memory\n");
    //printf("icode : %d",icode);
    if(mem_read())
    {
        read_write = 0;
        valM = read(mem_addr(),8);
        //printf("mem_read  valM : %lld\n", valM);
    } 
    if(mem_write())
    {
        read_write = 1;
        //printf("mem_write  valP : %lld  valA : %lld\n",valP,valA);
        if(icode & CALL)
        {
            write(mem_addr(),valP);
            val_memo = valP;
        }
        else
        {
            write(mem_addr(),valA);
            val_memo = valA;
        }
    }
    read_write = 2;
    addr_memo = mem_addr();
    //qDebug()<<icode<<valA<<valE<<mem_addr();
}
