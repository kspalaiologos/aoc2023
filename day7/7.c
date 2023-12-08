#include "../a.h"
typedef struct{C c[5];I b,t;}H;
I p=1;
I val(C s){
  switch(s){
    case'A':R 14;
    case'K':R 13;
    case'Q':R 12;
    case'J':R p==2?1:11;
    case'T':R 10;
    default:R s-'0';}}
I cmp(H*h1,H*h2){
  IF(h1->t!=h2->t,R h1->t-h2->t)
  Fi(5,IF(h1->c[i]!=h2->c[i],R val(h1->c[i])-val(h2->c[i])))}
I cmpi(I*a,I*b)_(*b-*a)
void sh(H* h) {
  I cm[13]={0},jk=0;Fi(5,IF(p==2&&h->c[i]=='J',jk++)ELSE(++cm[val(h->c[i]) - 2]))
  qsort(cm,13,4,cmpi);
  switch(cm[0]+=jk){
    case 1:h->t=0;break;
    case 2:h->t=cm[1]==2?2:1;break;
    case 3:h->t=cm[1]==2?4:3;break;
    default:h->t=cm[0]+1;}}
I solve(FILE* fp) {
  H h[1024];I hl=0,ans=0;
  W(fscanf(fp,"%s %d\n",h[hl].c,&h[hl].b)==2)sh(&h[hl++]);
  qsort(h,hl,16,cmp);Fi(hl,ans+=h[i].b*(i+1));R ans;}
I main() {
  FILE*fp=fopen("input.txt","r");
  I ans1,ans2;p=1,ans1=solve(fp);rewind(fp);p=2,ans2=solve(fp);
  printf("%d\n%d\n",ans1,ans2);}