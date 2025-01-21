#include <stdio.h>

#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    uint16_t s_len = strlen(s);
    int lp_s = 0, lp_e = 0;
    uint16_t longest_len = 0; 
    char l_char, r_char;  

    for (int start = 0; start < s_len; start++) {
        l_char = s[start];
        for (int end = s_len - 1; end >= start; end--) {
            printf("Start: %d | End: %d\n\r", start, end);
	    if (longest_len > end - start) break;

            r_char = s[end];
	    bool is_palindrome = true;
            
            for (int counter = 0; start + counter <= end - counter; counter++) {
                l_char = s[start + counter];
                r_char = s[end - counter];

                if (l_char != r_char) {
                    l_char = s[start]; 
		    printf("Break: %c (%d) - %c (%d)\n\r", l_char, start + counter, r_char, end - counter);
		    is_palindrome = false;
		    break;
                }

		printf("OK: %c (%d) - %c (%d)\n\r", l_char, start + counter, r_char, end - counter);
            }

            if (is_palindrome) {
                l_char = s[start];

                if ((end - start) > longest_len) {
                    longest_len = (end - start);
                    lp_s = start;
                    lp_e = end;
                }
            }
        }
    }

    char* palindrome = (char*)malloc(sizeof(char) * (lp_e - lp_s + 2));
    strncpy(palindrome, &s[lp_s], lp_e - lp_s + 1);
    palindrome[lp_e - lp_s + 1] = '\0';

    return palindrome;
}

char* manacher(char* s) {
    int N = strlen(s);
    N = 2 * N + 1;
    char* pS = (char*)malloc(sizeof(char) * (N + 1));
    for (int i = 0; i < N; i++) {
        pS[i] = i % 2 == 0 ? '#' : s[i/2]; 
    }
    pS[N] = '\0';
    
    int* p_radius = (int*)malloc(sizeof(int) * N);
    memset(p_radius, 0, N);

    int R = 0;
    int C= 0;
    for (int i = 0; i < N; i++) {  
        int i_mirrored = C- (i -C);

        if (R > i) p_radius[i] = R - i < p_radius[i_mirrored] ? R - i : p_radius[i_mirrored];
        else p_radius[i] = 0;

        while (
            i + (p_radius[i] + 1) < N && i - (p_radius[i] + 1) >= 0 &&
            pS[i + (p_radius[i] + 1)] == pS[i - (p_radius[i] + 1)]
        ) p_radius[i]++;


        if (i + p_radius[i] > R) {
            C= i;
            R = i + p_radius[i];

        }
    }

    int maxRadius = 0;
    int maxCenter = 0;
    for (int i = 0; i < N; i++) {
        if (p_radius[i] > maxRadius) {
            maxRadius = p_radius[i];
            maxCenter = i; 
        }
    }

    char* preprocessing_palindrome = (char*)malloc(sizeof(char) * (2 * maxRadius + 2));
    strncpy(preprocessing_palindrome, &pS[maxCenter - maxRadius], (2 * maxRadius + 1));
    preprocessing_palindrome[2 * maxRadius + 1] = '\0';

    char* palindrome = (char*)malloc(sizeof(char) * (maxRadius + 2));
    for (int i = 0; i < 2 * maxRadius + 1; i++) {
        i++;
        palindrome[i/2] = preprocessing_palindrome[i];
    }
    palindrome[maxRadius + 1] = '\0';

    free(preprocessing_palindrome);
    free(pS);

    return palindrome;
}

int main() {
	char* s = "cbbcd"; 
	// char* p = longestPalindrome(s);
	char* p = manacher(s);

	printf("\n\n\rOriginal: %s\n\rLongest Palindrome: %s\n\r", s, p);

	return 0;
}

