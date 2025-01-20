#include <stdio.h>

#include <string.h>
#include <stdint.h>

int lengthOfLongestSubstring(char* s) {
    int s_len = strlen(s), lss_len = 0;
    int p_s = 0, val = 0;
    uint8_t chars[127] = {0};

    for (int counter = 0; p_s + counter < s_len; counter++) {
        chars[s[p_s + counter]]++;
        if (counter + 1 > lss_len && chars[s[p_s + counter]] <= 1) {
            lss_len = counter + 1;
        }
        while (chars[s[p_s + counter]] > 1) {
            chars[s[p_s]]--;
            p_s++; counter--;
        }

    }

    return lss_len;
}

int main() {
    int i = lengthOfLongestSubstring("ABABCCECD");

    printf("\n\n\n\r Len: %d \n\n\n\r", i);

    return 0;
}