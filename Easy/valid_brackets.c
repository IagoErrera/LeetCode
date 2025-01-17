#include <stdio.h>
#include <string.h>

#include <stdbool.h> 


void print_bits(unsigned long long num) {
    for (int i = 63; i >= 0; i--) {
        printf("%llu", (num >> i & 1));
    }

    printf("\n\r");
}   

bool isValid(char* s) {
    unsigned long long fc[strlen(s) / 32];


    int i = 0;
    int list_select_index = 0, list_index = 0;
    int insert_val = -1, remove_val = -1;
    while (s[i] != '\0') {
        printf("i: %d\n\r", i);

        switch (s[i])
        {
        case '(':
            insert_val = 1;
            break;
        case '{':
            insert_val = 2;
            break;
        case '[':
            insert_val = 3;
            break;
        case ')':
            remove_val = 1;
            break;
        case '}':
            remove_val = 2;
            break;
        case ']':
            remove_val = 3;
            break;
        default:
            break;
        }

        if (list_index < 0 || list_select_index < 0) {
            return false;
        }

        if (insert_val != -1) {
            fc[list_select_index] &= ~((unsigned long long)(0b11) << 2 * (list_index));
            fc[list_select_index] |= (unsigned long long)(insert_val) << 2 * (list_index++);
            
            if (list_index == 32) {
                list_select_index++;
                list_index = 0;
            }

            insert_val = -1;
        } else if (remove_val != -1) {
            if (list_index == 0) {
                if (list_select_index == 0) {
                    return false;
                } else {
                    list_select_index--;
                    list_index = 32;
                }
            }
            
            if (((fc[list_select_index] >> 2 * (--list_index)) & 0b11) != remove_val) {
                return false;
            }

            remove_val = -1;
        }

        i++;
    }    

    if (list_index != 0 || list_select_index != 0) {
        return false;
    }

    return true;
}

int main() {
    char* s = "()";
    bool valid = isValid(s);
    printf("Is valid: %s\n\r", valid ? "yes" : "no");
    printf("Len: %lu", strlen(s));
    return 0;
}