
#include "../a.h"

SV gm(I gmx[4], C * b) {
    W(!isdigit(*b))b++;gmx[0]=atoi(b);W(isdigit(*b))b++;
    W(*b) {
        W(!isdigit(*b))b++;I num=atoi(b);W(isdigit(*b))b++;b++;
        if(!strncmp(b,"red",3)){IF(num>gmx[1],gmx[1]=num);b+=3;}
        else if(!strncmp(b,"green",5)){IF(num>gmx[2],gmx[2]=num);b+=5;}
        else if(!strncmp(b,"blue",4)){IF(num>gmx[3],gmx[3]=num);b+=4;}}}

SI p1(I gmx[4])_(gmx[1]>12||gmx[2]>13||gmx[3]>14?0:gmx[0])
SI p2(I gmx[4])_(gmx[1]*gmx[2]*gmx[3])

I main(V) {
    FILE*input=fopen("input.txt","r");
    I sum1=0,sum2=0;
    W (!feof(input)) {
        C buf[256]={0};fgets(buf,256,input);IF(!*buf,continue)
        I gmx[4]={0};gm(gmx,buf);sum1+=p1(gmx),sum2+=p2(gmx); }
    printf("%d\n%d\n",sum1,sum2); }

