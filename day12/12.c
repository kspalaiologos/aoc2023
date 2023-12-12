#include"../a.h"
L ch[512][512];
L cp2(I hi,I si,I nh,I ns,I*h,C*s){
    IF(hi==nh,R 1)IF(si<ns&&ch[hi][si]!=-1,R ch[hi][si])L c=0,v;
    F_(i,si,ns-h[hi]+1,v=1;Fj(h[hi],IF(s[i+j]=='.',v=0))
        IF(i+h[hi]<ns&&s[i+h[hi]]=='#',v=0)IF(i>0&&s[i-1]=='#',v=0)
        IF(hi==nh-1,F_(j,i+h[hi]+1,ns,IF(s[j]=='#',v=0)))
        IF(v,c+=cp2(hi+1,i+h[hi]+1,nh,ns,h,s))
        IF(s[i]=='#',break))IF(si<ns,ch[hi][si]=c)R c;}
I cp(I*h,I nh,C*s,I ns){
  IF(nh<=0,R 1)I t=0,v;Fi(ns-h[0]+1,
    v=1;Fj(h[0],IF(s[i+j]=='.',v=0))IF(i+h[0]<ns&&s[i+h[0]]=='#',v=0)
    IF(i>0&&s[i-1]=='#',v=0)IF(nh==1,F_(j,i+h[0]+1,ns,IF(s[j]=='#',v=0)))
    IF(v,t+=cp(&h[1],nh-1,&s[i+h[0]+1],ns-i-h[0]-1))IF(s[i]=='#',break))R t;}
I main() {
  FILE*f=fopen("input.txt","r");
  L t=0,t2=0;W(!feof(f)){
    C s[512],c;I h[512],nh=0,ns;fscanf(f,"%s ",s);
    do fscanf(f,"%d",&h[nh++]);W((c=fgetc(f))==',');
    ns=strlen(s);t+=cp(h,nh,s,ns);
    Fi(5,s[(ns+1)*i-1]='?';Fj(ns,s[j+(ns+1)*i]=s[j]))
    ns=ns*5+4;Fi(5,Fj(nh,h[j+nh*i]=h[j]))nh*=5;
    Fi(nh,Fj(ns,ch[i][j]=-1))t2+=cp2(0,0,nh,ns,h,s);}
  printf("%d\n%ld\n",t,t2);}