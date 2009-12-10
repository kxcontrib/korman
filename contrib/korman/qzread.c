/*
zread:`:qzread 2:(`zread;3)
zcount:{0x0 sv reverse read1(x;-4+-7!x)}
fs:{[f;s;c;b]{[f;s;b;x]i:1+last where"\n"=r:zread[s;x;b];f i#r;x+i}[f;s;b]/[c>;0j]}
fs[{process x};`file.gz;zcount `file.gz;131000]
*/
#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include "../include/k.h"
K zread(K x,K y,K z){
    char *buf=malloc(z->i);int err; 
    gzFile in=gzopen(xs,"rb");
    P(in==NULL,krr("can't gzopen"));
    if(-1==gzseek(in,y->j,SEEK_SET)){O("%s\n",gzerror(in,&err));R krr("gzerror");}
    int len=gzread(in,buf,z->i);
    if(len<0){O("%s\n",gzerror(in,&err));R krr("gzerror");}
    P(gzclose(in)!=Z_OK,krr("failed gzclose"));
    K tmp=kpn(buf,len);
    free(buf);
    R tmp;
}
