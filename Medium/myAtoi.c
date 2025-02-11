#include <stdio.h>

#include <limits.h>

#define MAX_INT_DIV10 214748364 // MAX_INT / 10

int myAtoi(char* s) {
    int i = 0;
    while (s[i] == 32) i++;

    int signal = 1;
    if (s[i] == '-') {
        signal = -1;
        i++;
    } else if (s[i] == '+') i++;

    int out = 0;
    while (s[i] > 47 && s[i] < 58) {
        if (
            signal == 1 &&
            (out > MAX_INT_DIV10 ||
            (out == MAX_INT_DIV10 && s[i] >= 55))
        ) return INT_MAX;
        else if (
            signal == -1 && 
            (out > MAX_INT_DIV10 ||
            (out == MAX_INT_DIV10 && s[i] >= 56))
        ) return INT_MIN;

        out *= 10;
        out += s[i] - 48;
        i++;
    }

    return signal * out;
}

int main(void) {
    int a = myAtoi("-2147483647");

    printf("%d\n\r", a);

    return 0;
}