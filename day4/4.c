
#include "../a.h"

I g[209][36], sc[209], cp[209];

I main(V) {
    FILE*f=fopen("input.txt", "r");
    C*p,buf[1024];I p1s=0,p2s=0;
    for(I i=0,j;fgets(buf,1024,f);i++) {
        j=0,p=buf;W(*p){W(!isdigit(*p)&&*p)p++;g[i][j++]=atoi(p);W(isdigit(*p)&&*p)p++;}}
    Fi(209,I c[100]={0};Fj(35,c[g[i][j+1]]++)Fj(100,c[j]==2&&sc[i]++)cp[i]=1)
    Fi(209,p1s+=sc[i]==0?0:1<<sc[i]-1;Fj(sc[i],j+i<208&&(cp[j+i+1]+=cp[i])))
    Fi(209,p2s+=cp[i])
    printf("%d\n%d\n",p1s,p2s);
}

