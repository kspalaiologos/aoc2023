
#include "../a.h"

I g[209][36], sc[209], cp[209];

I main(V) {
    FILE*f=fopen("input.txt", "r");
    // volatile struct timespec t0, t1; clock_gettime(CLOCK_REALTIME, &t0);
    C*p,buf[1024];I p1s=0,p2s=0;
    for(I i=0,j;fgets(buf,1024,f);i++) {
        j=0,p=buf+10;W(*p){W(!isdigit(*p)&&*p)p++;if(!*p)continue;
        IF(isdigit(p[1]),g[i][j++]=10*(p[0]-'0')+(p[1]-'0');p+=2)
        ELSE(g[i][j++]=p[0]-'0';p++)}}
    Fi(209,I c[100]={0};Fj(35,c[g[i][j]]++)Fj(100,c[j]==2&&sc[i]++)cp[i]=1)
    Fi(209,p1s+=sc[i]==0?0:1<<sc[i]-1;Fj(sc[i],j+i<208&&(cp[j+i+1]+=cp[i])))
    Fi(209,p2s+=cp[i])
    // clock_gettime(CLOCK_REALTIME, &t1);
    // printf("%lf ms\n", (t1.tv_nsec-t0.tv_nsec)/1000000.0);
    printf("%d\n%d\n",p1s,p2s);
}
