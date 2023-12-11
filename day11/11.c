#include"../a.h"
C g[140][140],h[140],v[140];T q[500][2];L h2[140],v2[140],gn,d;
L cab(L i,L j)_(abs(h2[q[i][0]]-h2[q[j][0]])+abs(v2[q[i][1]]-v2[q[j][1]]))
V scal(L s){
  L x=0,y=0;Fi(140,h2[i]=x+=!h[i]?s:1,v2[i]=y+=!v[i]?s:1)
  d=0;Fi(gn,Fj(i,d+=cab(i,j)))printf("%ld\n",d);}
I main() {
    FILE*f=fopen("input.txt","r");
    Fi(140,Fj(140,g[i][j]=fgetc(f)=='#')fgetc(f));
    Fi(140,Fj(140,h[i]|=g[i][j],v[i]|=g[j][i]))
    Fi(140,Fj(140,IF(g[i][j],q[gn][0]=i;q[gn][1]=j;gn++)))
    scal(2);scal(1E6);}