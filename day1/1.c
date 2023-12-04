
#include "../a.h"

SI p1(C*z) {
    I f=0,l=strlen(z);
    W(!isdigit(z[f])&&z[f])f++;
    W(!isdigit(z[l])&&l)l--;
    R 10*(z[f]-'0')+(z[l]-'0'); }

SI st(C*w,C*z) {W(*w)IF(*w!=*z,R 0)ELSE(w++,z++)R 1;}

SI num(C*z) {
    if(st("one",z))R 1;
    if(st("two",z))R 2;
    if(st("three",z))R 3;
    if(st("four",z))R 4;
    if(st("five",z))R 5;
    if(st("six",z))R 6;
    if(st("seven",z))R 7;
    if(st("eight",z))R 8;
    if(st("nine",z))R 9;
    if(isdigit(*z))R*z-'0';
    R-1; }

SI p2(C*z) {
    I f=-1,l=-1,d;
    W(*z) {
        d=num(z++);
        IF(d!=-1,IF(f==-1,f=d)ELSE(l=d)) }
    R 10*f+(l==-1?f:l);
}

I main(V) {
    FILE*in=fopen("input.txt","r");
    I s1=0,s2=0;
    W(!feof(in)) {
        C buf[128]={0};fgets(buf,128,in);
        IF(!*buf,continue)
        s1+=p1(buf),s2+=p2(buf); }
    printf("%d\n%d\n", s1, s2);
}

