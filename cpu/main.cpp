#include "mainwindow.h"
#include <QApplication>
#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>
#include "cpu.h"
#include <map>
#include "mainwindow.h"
int currentStep = 0;
cpu PIP;
QString text;
std::map<long long,std::string> comand;
std::string now_comand;
long long Icode ,Ifun, ValC, ValP, now_pc,ValA, ValB, DstE, DstM,ValE,addr_memo,val_memo,ValM;
int read_write = 0,state = 1,is_opq = 0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //read(PIP);
    MainWindow w;
    w.click();
    w.show();
    return a.exec();
}
