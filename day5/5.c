#include"../a.h"
typedef struct{L b,l;}Rc;
Rc*r;L vl;
V ins(L b,L l){r[vl].b=b;r[vl].l=l;vl++;}
I main() {
    FILE*inf=fopen("input.txt", "r");
    C buf[300][300],gn[20],*p=buf[0]+7;I ln,sn=0;L ids[20],sum1=0,sum2=0,lc;
    for(ln=0;ln<208&&fgets(buf[ln], 200,inf);ln++);
    W(*p&&*p!='\n')ids[sn++]=strtoll(p, &p, 10),p++;
    F_(i,2,ln,p=buf[i];IF(!isdigit(*p),IF(*p<'a',memset(gn,0,sn))continue)
        L dest=strtoll(p,&p,10),src=strtoll(p+1,&p,10),l=strtoll(p+1,&p,10);
        Fj(sn,IF(gn[j],continue)L d=ids[j]-src;IF(d>=0&&d<l,ids[j]=dest+d;gn[j]=1)))
    sum1=ids[0];Fj(sn,IF(ids[j]<sum1,sum1=ids[j]))printf("%llu\n",sum1);
    r=malloc(512*sn);vl=sn/2;lc=vl;p=buf[0]+7;
    Fi(sn/2,r[i].b=strtoll(p,&p,10),r[i].l=strtoll(p+1,&p,10))
    F_(i,2,ln,p=buf[i];IF(!isdigit(*p),IF(*p<'a',lc=vl)continue)
        L dest=strtoll(p,&p,10),src=strtoll(p+1,&p,10),l=strtoll(p+1,&p,10);
        Fj(lc,IF(r[j].l<=0,continue)L d=r[j].b-src;
            IF (d>=0&&d<l,L nns=dest+d,nnl=l-d<=r[j].l?l-d:r[j].l;
                r[j].b+=nnl,r[j].l-=nnl;ins(nns, nnl))
            IF (d<0&&-d<r[j].l,if(src+l<r[j].b+r[j].l)ins(dest,l),ins(src+l,r[j].l+d-l);
                else ins(dest,r[j].l+d);r[j].l=-d)))
    sum2=0xFFFFFFFF;Fj(vl,IF(r[j].l&&r[j].b<sum2,sum2=r[j].b))printf("%llu\n", sum2);}