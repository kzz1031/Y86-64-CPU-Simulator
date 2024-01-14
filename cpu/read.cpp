#include<stdio.h>
#include<string.h>
#include<QDebug>
#include<QString>
#include "cpu.h"
#include "read.h"
extern QString text;
extern std::map<long long,std::string> comand;

void read(cpu &pp){
    ll addr,addr2,line=0;
    char s[1030],ch[1030];
    FILE* fin;

    QString Sfin = "E:\\Qt_Program\\cpu\\test\\" + text;
    qDebug()<<Sfin<<"reading...";
    fin = fopen(Sfin.toStdString().c_str(),"r");
    if(fin == nullptr) {
        perror("Error opening file");
        qDebug()<<"error";
        return;
    }

    while(fgets(s,1000,fin)){
        qDebug()<<s;
        //puts(s);
        ++line;

        //if(line==1) continue;
        sscanf(s,"%llx: %s",&addr,ch);
        comand[addr] = ch;
        //printf("%llx %s\n",addr,ch);
        pp.max_addr = addr + 8;
        int len = strlen(ch)/2;
        int st = strlen(ch)-1;
        for(addr2=addr+len-1;addr2>=addr;addr2--){
            char hexString[3];
            hexString[1] = ch[st];
            st--;
            hexString[0] = ch[st];
            st--;
            hexString[2] = '\0';
            int intValue = strtol(hexString, NULL, 16);
            //printf("%d\n",intValue);
            pp.writeByte(addr2,intValue);
            
            if(addr2==addr) break;
        }
    }

    puts("Read Finished!");
    fclose(fin);
}
