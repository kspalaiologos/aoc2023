
#ifndef _A_H
#define _A_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

typedef int I;
typedef long L;
typedef void V;
typedef char C;
typedef double D;
#define S static
#define SI static int
#define SV static void
#define SC static char
#define W while
#define R return
#define IF(c,b...) if(c){b;}
#define ELSE(b...) else{b;}
#define _(a...) {return({a;});}
#define Fi(n,a...) for(int i=0;i<n;i++){a;}
#define Fj(n,a...) for(int j=0;j<n;j++){a;}
#define Fx(n,a...) for(int x=0;x<n;x++){a;}
#define Fy(n,a...) for(int y=0;y<n;y++){a;}
#define F_(z,i,n,a...) for(int z=i;z<n;z++){a;}
#define F1(n,x,a...) for(i32 i=0;i<n;i+=x){a;}
#define INL P inline __attribute__((always_inline))
#define AFF(X) if(!(X))__builtin_unreachable();
#define L(c) __builtin_expect((c),1)


#endif

