
#include "../a.h"

SC d[140][142];

SI rn(I dy,I dx) {
    IF(dy<0||dy>=140||dx<0||dx>=140,R 0)
    IF(!isdigit(d[dy][dx]),R 0)
    W(isdigit(d[dy][dx])&&dx>=0)dx--;dx++;
    R atoi(&d[dy][dx]); }

SV p(V) {
    I sum1=0,sum2=0;
    Fy(140,Fx(140,IF(strchr("*@#-=/+%$&",d[y][x]),
        I mat[3][3]={0},n=0,p=1;
        F_(dy,y-1,y+2,F_(dx,x-1,x+2,mat[dy-y+1][dx-x+1]=rn(dy,dx)))
        Fi(3, IF(mat[i][0],sum1+=mat[i][0],n++,p*=mat[i][0])
              IF(mat[i][1]!=mat[i][2]&&mat[i][2],sum1+=mat[i][2],n++,p*=mat[i][2])
              IF(mat[i][0]!=mat[i][1]&&mat[i][1],sum1+=mat[i][1],n++,p*=mat[i][1]))
        IF(n==2,sum2+=p))))
    printf("%d\n%d\n", sum1, sum2); }

I main(V) {
    FILE*in=fopen("input.txt", "r");
    Fi(140,fgets(d[i],142,in));
    p(); }
