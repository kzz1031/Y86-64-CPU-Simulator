#include "cpu.h"
#include "instruction_def.h"
#include <QDebug>
#include <stdio.h>
extern int  currentStep;

void cpu::control()
{
    qDebug()<<"controlling...";
}

bool cpu::Go()
{
    stat = AOK ;
    if (currentStep == 0) {
        qDebug()<<"fetching...";
        fetch();

    } else if (currentStep == 1) {
        qDebug()<<"decoding...";
        decode();
    } else if (currentStep == 2) {
        qDebug()<<"excuting...";
        execute();
    } else if (currentStep == 3) {
        qDebug()<<"memory...";
        _Memory();
    } else if (currentStep == 4) {
        qDebug()<<"writeback...";
        writeback();
    } else if (currentStep == 5) {
        qDebug()<<"update_pc...";
        update_pc();
        print();
    }
    currentStep++;

    if (currentStep > 5) {
        currentStep = 0;
    }
    max_addr = std::max(max_addr,reg[RSP]);
    if(stat != AOK){
        return false;
    }

    return true;
}
