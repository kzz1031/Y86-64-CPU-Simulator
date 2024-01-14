#include "cpu.h"
#include "instruction_def.h"
#include <stdio.h>
bool cpu::Go()
{
    stat = AOK ;
    fetch();
    decode();
    execute();
    _Memory();
    writeback();  
    update_pc();
    print();
    max_addr = std::max(max_addr,reg[RSP]);
    if(stat != AOK){
        return false;
    }

    return true;
}