#include"../a.h"
T h[30000][2],w[10],tl;C t[300];
T hk(C b[3])_(b[0]*1024+b[1]*32+b[2])
T rk(FILE*f)_(C b[3];Fi(3,b[i]=fgetc(f)-'A')hk(b))
L r(I s,L p)_((s&31)==25?p:r(h[s][t[p%(tl-1)]],p+1))
L gcd2(L a,L b)_(b?gcd2(b,a%b):a)
L gcd(I k)_(L g=w[0];Fi(k,g=gcd2(g,w[i]))g)
I main() {
    FILE*f=fopen("input.txt","r");
    fgets(t,300,f);tl=strlen(t);Fi(tl,t[i]=t[i]!='L')fgetc(f);
    W(!feof(f)){C s[4];T k=rk(f);if(k<0)break;fread(s,1,4,f);
        h[k][0]=rk(f);fread(s,1,2,f);h[k][1]=rk(f);fread(s,1,2,f);}
    printf("%d\n",r(0,0));
    I k=0;Fi(859,if(h[i<<5][0]&&h[i<<5][1])w[k++]=r(i<<5,0));
    L c=gcd(k),p=1;Fi(k,p*=w[i]/c);printf("%lld\n",p*c);
}