
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static char data[140][142];

static int read_number(int dy, int dx) {
    if (dy < 0 || dy >= 140 || dx < 0 || dx >= 140) return 0;
    if (!isdigit(data[dy][dx])) return 0;
    while(isdigit(data[dy][dx]) && dx >= 0) dx--; dx++;
    return atoi(&data[dy][dx]);
}

static void p1() {
    int sum1 = 0, sum2 = 0;
    for (int y = 0; y < 140; y++) {
        for (int x = 0; x < 140; x++) {
            if (strchr("*@#-=/+%$&", data[y][x])) {
                int mat[3][3] = { 0 };
                for (int dy = y - 1; dy <= y + 1; dy++) {
                    for (int dx = x - 1; dx <= x + 1; dx++) {
                        mat[dy - y + 1][dx - x + 1] = read_number(dy, dx);
                    }
                }
                int n = 0, p = 1;
                for (int i = 0; i < 3; i++) {
                    if (mat[i][0]) sum1 += mat[i][0], n++, p *= mat[i][0];
                    if (mat[i][1] != mat[i][2] && mat[i][2]) sum1 += mat[i][2], n++, p *= mat[i][2];
                    if (mat[i][0] != mat[i][1] && mat[i][1]) sum1 += mat[i][1], n++, p *= mat[i][1];
                }
                if (n == 2) sum2 += p;
            }
        }
    }
    printf("%d %d\n", sum1, sum2);
}

int main(void) {
    FILE * input = fopen("input.txt", "r");
    for(int i = 0; i < 140; i++) { fgets(data[i], 142, input); }
    fclose(input);
    p1();
}
