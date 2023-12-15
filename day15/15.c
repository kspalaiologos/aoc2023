#include"../a.h"

typedef struct{C l[10];I fc;}Lens;
typedef struct{Lens l[512];I sz;}Box;
Box b[256];
I cks(C*l)_(I r=0;Fi(strlen(l),r=((r+l[i])*17)&0xFF)r)
void ab(C*l, I fc) {
  I n=cks(l),h=0;
  Fi(b[n].sz,if(!strcmp(b[n].l[i].l, l))h=1,b[n].l[i].fc=fc)
  if(!h){strcpy(b[n].l[b[n].sz].l,l);b[n].l[b[n].sz++].fc=fc;}}
void rb(C*l){
  I n=cks(l),ind=-1;
  Fi(b[n].sz,IF(!strcmp(b[n].l[i].l, l),ind=i;break))
  if(ind!=-1){b[n].sz--;Fi(ind+b[n].sz,b[n].l[i+ind]=b[n].l[i+ind+1])}}
L hc=0,s1=0;I h(I c)_(if(c==','||c==EOF||c=='\n')s1+=hc,hc=0;else hc=((hc+c)*17)&0xff;c)
I main() {
  FILE*f=fopen("input.txt","r");
  C l[10];I lsz=0;
  W (!feof(f)){
    I c=h(fgetc(f));if(c=='\n')break;
    if(c=='='){I fc=h(fgetc(f))-'0';c=h(fgetc(f));ab(l,fc);l[0]=lsz=0;
    }else if(c == '-')c=h(fgetc(f)),rb(l),l[0]=lsz=0;
    else l[lsz]=c,l[++lsz]=0;}
  L s2=0;Fi(256,Fj(b[i].sz,s2+=(i+1)*(j+1)*b[i].l[j].fc))
  printf("%ld\n%ld\n", s1, s2);}