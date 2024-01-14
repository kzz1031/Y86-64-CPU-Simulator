#ifndef REGISTER_H
#define REGISTER_H

#define RAX 0
#define RCX 1
#define RDX 2
#define RBX 3
#define RSP 4
#define RBP 5
#define RSI 6
#define RDI 7
#define R8 8
#define R9 9
#define R10 10
#define R11 11
#define R12 12
#define R13 13
#define R14 14
#define RNONE 15

#define HALT 1
#define NOP 2
#define RRMOVQ 4
#define IRMOVQ 8
#define RMMOVQ 16
#define MRMOVQ 32
#define OPQ 64
#define JXX 128
#define CALL 256
#define RET 512
#define PUSHQ 1024
#define POPQ 2048

#define FNONE 0
#define ALUADD 0
#define ALUSUB 1
#define ALUAND 2
#define ALUXOR 3
#define ALUSHL 4
#define ALUSHR 5

#define AOK 1
#define HLT 2
#define ADR 3
#define INS 4


#define CCJMP 0
#define CCJLE 1
#define CCJL 2
#define CCJE 3
#define CCJNE 4
#define CCJGE 5
#define CCJG 6

#define ull unsigned long long
#define ll long long 
#endif
