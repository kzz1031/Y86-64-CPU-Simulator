#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextStream>
#include <QFile>
#include "cpu.h"
#include "read.h"
extern cpu PIP;
extern QString text;
extern long long Icode ,Ifun, ValC, ValP , now_pc, ValA, ValB, DstE, DstM,ValE,addr_memo,val_memo,ValM;
extern int  currentStep;
extern std::string now_comand;
extern int read_write,state,is_opq;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click()
{
    connect(ui->next_stage, &QPushButton::clicked, this, &MainWindow::on_next_stage_clicked);
    connect(ui->start,&QPushButton::clicked, this , &MainWindow::start_clicked);
}

void MainWindow::on_next_stage_clicked()
{
    PIP.Go();
    if(currentStep == 1)
    {
        QString qstr = QString::fromStdString(now_comand);
        QString text = QString::number(now_pc);
        ui->fetch->setStyleSheet("background-color: green;");
        ui->update->setStyleSheet("background-color: white;");
        ui->comand->setText("present PC :" + text + " : "+ qstr);
        ui->ifun->setText("ifun: " + QString::number(Ifun));
        ui->icode->setText("ifun: " + QString::number(Icode));
        ui->valC->setText("ifun: " + QString::number(ValC));
        ui->valP->setText("ifun: " + QString::number(ValP));
        ui->state->setText("PC STATE: " + QString::number(state));
        if(state == 1)
        {
            ui->state->setStyleSheet("background-color: green;");
        }


    }
    if(currentStep == 2)
    {
        ui->fetch->setStyleSheet("background-color: white;");
        ui->decode->setStyleSheet("background-color: green;");
        ui->valA->setText("valA: "+ QString::number(ValA));
        ui->valB->setText("valB: "+ QString::number(ValB));
        ui->dstE->setText("dstE: "+ QString::number(DstE));
        ui->dstM->setText("dstM: "+ QString::number(DstM));
    }
    if(currentStep == 3)
    {
        ui->decode->setStyleSheet("background-color: white;");
        ui->execute->setStyleSheet("background-color: green;");
        if(is_opq) ui->scc->setStyleSheet("background-color: green;");
        ui->valE->setText("valE: "+ QString::number(ValE));
    }

    if(currentStep == 4)
    {
        ui->execute->setStyleSheet("background-color: white;");
        ui->memory->setStyleSheet("background-color: green;");
        ui->scc->setStyleSheet("background-color: rgb(170, 170, 127);");
        ui->VAL->setText("VAL: "+ QString::number(val_memo));
        ui->addr->setText("Addr: "+ QString::number(addr_memo));
        if(read_write == 1)
        {
            ui->write->setStyleSheet("background-color: green;");
            ui->read->setStyleSheet("background-color: white;");
        }
        else if(read_write == 0)
        {
            ui->write->setStyleSheet("background-color: white;");
            ui->read->setStyleSheet("background-color: green;");
        }
    }
    if(currentStep == 5)
    {
        ui->memory->setStyleSheet("background-color: white;");
        ui->write_back->setStyleSheet("background-color: green;");
        ui->valE_2->setText("valE: "+ QString::number(ValE));
        ui->valM->setText("valM: "+ QString::number(ValM));
        ui->dstE_2->setText("dstE: "+ QString::number(DstE));
        ui->dstM_2->setText("dstM: "+ QString::number(DstM));
        ui->state->setText("PC STATE: " + QString::number(state));
        if(state != 1)
        {
            ui->state->setStyleSheet("background-color: red;");
        }
    }
    if(currentStep == 0)
    {
        QString qstr = QString::fromStdString(now_comand);
        QString text = QString::number(now_pc);
        ui->write_back->setStyleSheet("background-color: white;");
        ui->update->setStyleSheet("background-color: green;");
        ui->pc->setText("PC: "+ QString::number(now_pc));
        ui->comand->setText("present PC :" + text + " : "+ qstr);
        ui->state->setText("PC STATE: " + QString::number(state));
        if(state != 1)
        {
            ui->state->setStyleSheet("background-color: red;");
        }
    }

}

void MainWindow::start_clicked()
{
    text = ui->lineEdit->text();
    QString Sfin = "E:\\Qt_Program\\cpu\\test\\" + text;
    qDebug()<<"starting"<<Sfin;
    QFile file(Sfin);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString fileContent = in.readAll();
        file.close();
        ui->textBrowser->setPlainText(fileContent);
    } else {
        qDebug() << "Failed to open file: " << file.errorString();
    }
    read(PIP);
}
