#include<stdio.h>
#include<string.h>
#include "cpu.h"

void read(cpu &pp){
    ll addr,addr2,line=0;
    char s[1030],ch[1030];
    //FILE* fin;
    //fin = fopen("prog1.yo","r");
    while(fgets(s,1000,stdin)){
        
        //puts(s);
        ++line;

        //if(line==1) continue;
        sscanf(s,"%llx: %s",&addr,ch);
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

    //puts("Read Finished!");
    //fclose(fin);
}
