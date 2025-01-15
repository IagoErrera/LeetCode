#include <stdio.h>
#include <string.h>

#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefix = (char*)malloc(200 * sizeof(char));
    unsigned short int prefix_end = 0;
    int pos = 0;
    char character = '@';
    
    while (!prefix_end && character != '\0') {
         character = strs[0][pos];
        for (int i = 1; i < strsSize; i++) {
            if (character != strs[i][pos] || strs[i][pos] == '\0') {
                prefix_end = 1;
                break;
            } 
        }

        if (prefix_end == 0) prefix[pos++] = character;
    }

    prefix[pos] = '\0';
    return (char*)realloc(prefix, (pos + 1) * sizeof(char)); 
}

int main() {
    char* test[3] = {"flower","flight","fly"};

    char* pre = longestCommonPrefix(test, 3);
    int len = strlen(pre);

    printf("%s\n\r", pre);
    printf("%d\n\r", len);

    return 0;
}