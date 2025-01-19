#include <stdlib.h>
#include <stdio.h>

// Definition for singly-linked list.
 struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* n1 = l1; 
    struct ListNode* n2 = l2; 

    struct ListNode* lo = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    struct ListNode* current = lo; 

    lo->val = 0; lo->next = NULL;

    while (n1 != NULL && n2 != NULL) {
        if (n1 != NULL && n2 != NULL) {
            current->val = n1->val + n2->val;
            
            n1 = n1->next; n2 = n2->next;
        } else if (n1 != NULL) {
            current->val = n1->val;

            n1 = n1->next;
        } else {
            current->val = n2->val;

            n2 = n2->next;
        }
        
        printf("%d - ", current->val);

        if (n1 != NULL || n2 != NULL) {
            current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            current->next->val = 0; current->next->next = NULL;    
        }

        printf("%d\n\r", current->val);

        current = current->next;
    }

    return lo;
}

int main() {
    struct ListNode* list1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* list2 = (struct ListNode*)malloc(sizeof(struct ListNode*));

    struct ListNode* current_node = list1;
    current_node->val = 2;
    current_node->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
    current_node = current_node->next;
    current_node->val = 4;
    current_node->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
    current_node = current_node->next;
    current_node->val = 3;
    current_node->next = NULL;

    printf("List1--------------------------\n\r");
    current_node = list1;
    while (current_node != NULL) {
        printf("%d\n\r", current_node->val);
        current_node = current_node->next;
    }

    current_node = list2;
    current_node->val = 5;
    current_node->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
    current_node = current_node->next;
    current_node->val = 6;
    current_node->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
    current_node = current_node->next;
    current_node->val = 4;
    current_node->next = NULL;

    printf("List2--------------------------\n\r");
    current_node = list1;
    while (current_node != NULL) {
        printf("%d\n\r", current_node->val);
        current_node = current_node->next;
    }

    printf("Sum-------------------------\n\r");
    current_node = addTwoNumbers(list1, list2);
    while (current_node != NULL) {
        printf("%d\n\r", current_node->val);
        current_node = current_node->next;
    }

    return 0;
}