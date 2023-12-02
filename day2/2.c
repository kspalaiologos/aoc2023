
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void gm(int game_max[4], char * buffer) {
    while (!isdigit(*buffer)) buffer++;
    game_max[0] = atoi(buffer);
    while (isdigit(*buffer)) buffer++;
    while (*buffer != 0) {
        while (!isdigit(*buffer)) buffer++;
        int num = atoi(buffer);
        while (isdigit(*buffer)) buffer++;
        buffer++;
        if (!strncmp(buffer, "red", 3)) {
            if (num > game_max[1]) game_max[1] = num;
            buffer += 3;
        } else if (!strncmp(buffer, "green", 5)) {
            if (num > game_max[2]) game_max[2] = num;
            buffer += 5;
        } else if (!strncmp(buffer, "blue", 4)) {
            if (num > game_max[3]) game_max[3] = num;
            buffer += 4;
        }
    }
}

static int part1(int game_max[4]) {
    if (game_max[1] >= 12 || game_max[2] >= 13 || game_max[3] >= 14) {
        return 0;
    } else {
        return game_max[0];
    }
}

static int part2(int game_max[4]) {
    return game_max[1] * game_max[2] * game_max[3];
}

int main(void) {
    FILE * input = fopen("input.txt", "r");
    int sum1 = 0, sum2 = 0;
    while (!feof(input)) {
        char buf[256] = { 0 }; fgets(buf, 256, input);
        if (*buf == 0) continue;
        int game_max[4] = { 0 };
        gm(game_max, buf);
        sum1 += part1(game_max);
        sum2 += part2(game_max);
    }
    fclose(input);
    printf("%d\n%d\n", sum1, sum2);
}

