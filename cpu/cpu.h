#pragma once
#include<map>
#include "instruction_def.h"
#include<string>
class cpu{
    private:
        int cnt;
        std::map<ull,int>memo;
        ll reg[16]={0};
        int stat;
    public:
        bool Go();
        bool writeByte(ll addr,int val);
        bool write(ll addr,ll val);
        ll read(ll addr, int len);
        ll readByte(ll addr);
    private:
        int memoErro;

    public:
        void fetch();
        bool Need_regids(ll icode);
        bool Need_valC(ll icode);
        ll max_addr;
    private:
        ll pc=0,npc,valC;
        int icode,ifun;
        int rA,rB;
        ll valP;


    public:
        void decode();
        ll d_srcB();
        ll d_srcA();
        ll d_dstE();
        ll d_dstM();
    private:
        ll valA,valB,dstE,dstM;


    public:
        void execute();
        ll alufun();
        ll aluA();
        ll aluB();
        ll e_valE();
        ll e_valE_setcc();
        void ccupdate(int zf,int sf,int of);
        bool isTrue(int fun);
    private:
        bool cnd = 0;
        int ZF = 1, SF = 0, OF = 0;
        ll valE;

    public:
        void _Memory();
        ll mem_addr();

        bool mem_read();
        bool mem_write();
    private:
        ll valM;
    
    public:
        void writeback();
        void reg_write(int addr,ll val);

    public:
        void update_pc();
        void print();
    public:
        std::string r[16] = {
        "rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi",
        "r8", "r9", "r10", "r11", "r12", "r13", "r14"
    };
    public:
        void control();

};
