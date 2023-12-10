#include "../a.h"
#define DN 1
#define DE 2
#define DS 4
#define DW 8
I m[140][140],d[140][140];C cm[140][140];
typedef struct n{I i,j;struct n*next;}n;n*fr,*b;
V enq(I i,I j){if(!fr)fr=malloc(16),b=fr,fr->i=i,fr->j=j;else{n*m=malloc(16);m->i=i,m->j=j,b->next=m,b=m;}}
V deq(I*i,I*j){*i=fr->i;*j=fr->j;n*nf=fr->next;free(fr);fr=nf;}
I main() {
  FILE*f=fopen("input.txt","r");
  Fi(140,Fj(140,d[i][j]=-1;I ch=fgetc(f);cm[i][j]=ch;
    IF(ch=='|',m[i][j]=DN|DS)IF(ch=='-',m[i][j]=DE|DW)
    IF(ch=='L',m[i][j]=DN|DE)IF(ch=='J',m[i][j]=DN|DW)
    IF(ch=='7',m[i][j]=DS|DW)IF(ch=='F',m[i][j]=DS|DE)
    IF(ch=='.',m[i][j]=0)
    IF(ch=='S',m[i][j]=DN|DS,enq(i,j),d[i][j]=0,cm[i][j]='|'))fgetc(f);)
  W(fr){
    I i,j,dr;deq(&i,&j);dr=m[i][j];
    IF((dr&DN)&&i-1>=0&&d[i-1][j]==-1,d[i-1][j]=d[i][j]+1,enq(i-1,j))
    IF((dr&DS)&&i+1<140&&d[i+1][j]==-1,d[i+1][j]=d[i][j]+1,enq(i+1,j))
    IF((dr&DW)&&j-1>=0&&d[i][j-1]==-1,d[i][j-1]=d[i][j]+1,enq(i,j-1))
    IF((dr&DE)&&j+1<140&&d[i][j+1]==-1,d[i][j+1]=d[i][j]+1,enq(i,j+1))}
  I m=0,n=0;Fi(140,Fj(140,IF(d[i][j]>m,m=d[i][j])))
  printf("%d\n", m);
  Fi(140,Fj(140,IF(d[i][j]==-1,I l=0;Fx(j,
    IF(d[i][x]!=-1&&(cm[i][x]=='L'||cm[i][x]=='J'||cm[i][x]=='|'),l=!l))n+=l;cm[i][j]=l?'+':'.')))
  printf("%d\n",n);
}
