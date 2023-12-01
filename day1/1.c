
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Part 1
static int part1(char * line) {
    // find first digit from the beginning of line
    int first = 0;
    while (!isdigit(line[first]) && line[first] != 0) first++;
    int last = strlen(line);
    while (!isdigit(line[last]) && last != 0) last--;
    return 10 * (line[first] - '0') + (line[last] - '0');
}

// Part 2
static int starts(char * word, char * line) {
    while (*word != 0)
        if (*word != *line) return 0; else word++, line++;
    return 1;
}

static int number(char * line) {
    if (starts("one", line)) return 1;
    if (starts("two", line)) return 2;
    if (starts("three", line)) return 3;
    if (starts("four", line)) return 4;
    if (starts("five", line)) return 5;
    if (starts("six", line)) return 6;
    if (starts("seven", line)) return 7;
    if (starts("eight", line)) return 8;
    if (starts("nine", line)) return 9;
    if (isdigit(*line)) return *line - '0';
    return -1;
}

static int part2(char * line) {
    int first = -1, last = -1;
    while (*line != 0) {
        int num = number(line);
        if (num != -1) {
            if (first == -1) first = num;
            else last = num;
        }
        line++;
    }
    if (last == -1) last = first;
    return 10 * first + last;
}

int main(void) {
    FILE * input = fopen("input.txt", "r");
    int sum1 = 0, sum2 = 0;
    while (!feof(input)) {
        char buf[128] = { 0 }; fgets(buf, 128, input);
        if (*buf == 0) continue;
        sum1 += part1(buf);
        sum2 += part2(buf);
    }
    fclose(input);
    printf("%d\n%d\n", sum1, sum2);
}

