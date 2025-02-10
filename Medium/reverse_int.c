#include <stdio.h>
#include <limits.h>

int reverse(int x){
    int out = 0;
    int digits = 0;

    while (x != 0) {
        if (out >= INT_MAX / 10 + (INT_MAX % 10 > 0 ? 1 : 0)  || out <= INT_MIN / 10 - (INT_MIN % 10 < 0 ? 1 : 0)) return 0;
        out *= 10;
        out += x % 10;
        x /= 10;
    }

    return out;
}

int main() {
    long int x = reverse(1534236469);
    
    printf("%ld\n\r", x);

    return 0;
}