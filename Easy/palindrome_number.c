#include <stdio.h>
#include <stdbool.h>

#include <stdlib.h>

bool isPalindrome_1(int x) {
    if (x < 0) return false;

    int digits = 0;
    for (int num = x; num > 0; num /= 10) digits++; 
    if (x == 0) digits = 1;

    char* num = (char*)malloc(sizeof(char) * (digits + 1));
    sprintf(num, "%d", x);

    int i = 0, j = digits - 1;
    bool is_palindrome = true;
    while (i < j && is_palindrome) {
        
        if (num[i] != num[j]) is_palindrome = false; 
        
        i++;
        j--;
    }

    return is_palindrome;
}

bool isPalindrome_2(int x) {
    if (x < 0 || (x != 0 && x%10 == 0)) return false;
    long check = 0;
    int num = x;
    while (check < x) {
        check = 10*check + num % 10;
        printf("Check: %ld\n\r", check);
        num /= 10;
        printf("Num: %d\n\r", num);
    }

    return check == x;
}

int main() {
    bool is_palindrome = isPalindrome_2(1234567899);

    if (is_palindrome) printf("Is palindrome\n\r");
    else printf("Isn't palindrome\n\r");

    return 0;
}

