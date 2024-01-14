#include "cpu.h"
#include "instruction_def.h"

void cpu::print()
{
    printf("- PC: %lld\n",pc);
    printf("  REG:\n");
    for(int i = 0;i <= 14;i++)
        printf("    %s: %lld\n",r[i].c_str(),reg[i]);
    printf("  MEM:\n");
    for(ll i = 0;i <= max_addr;i += 8)
    {
        ll memo_out = read(i,8);
        if(memo_out == 0) continue;
        printf("    %lld: %lld\n",i,memo_out);
    }
    printf("  CC:\n");
    printf("    ZF: %d\n",ZF);
    printf("    SF: %d\n",SF);
    printf("    OF: %d\n",OF);
    printf("  STAT: %d\n",stat);
}