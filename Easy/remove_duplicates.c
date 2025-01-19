#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    printf("numsSize: %d\n\e", numsSize);

    int current_index = 1;
    for (int i = 1; i < numsSize; i++) {
        printf("nums[i]: %d", nums[i]);
        if (nums[i] > nums[current_index - 1]) {
            nums[current_index] = nums[i];
            current_index++;
        } 
    } 

    return current_index;
}

int main() {
    int a[] = {1,1,2,3,3};

    int k = removeDuplicates(a, 5);

    for (int i = 0; i < k; i++) {
        printf("%d\n\r", a[i]);
    }

    return 0;
}