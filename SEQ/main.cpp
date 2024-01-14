#include <stdlib.h>
#include <stdio.h>

#include "cpu.h"
#include "read.h"
cpu PIP;

int main()
{
    read(PIP);
    while(1)
    {
        if(!PIP.Go()) break;
    }
    return 0;
}
