#include <stdlib.h>
#include <stdio.h>

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
 };
 

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* list_head = NULL;
    struct ListNode* current_node = NULL;
    struct ListNode* last_node = NULL;

    while (list1 != NULL || list2 != NULL) {
        if (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                current_node = list1;
                list1 = list1->next;
            } else {
                current_node = list2;
                list2 = list2->next;
            }
        } else if (list1 != NULL) {
            current_node = list1;
            list1 = list1->next;
        } else {
            current_node = list2;
            list2 = list2->next;
        }
        
        if (current_node != NULL) current_node->next = NULL;
        if (list_head == NULL) list_head = current_node;
        else last_node->next = current_node;
        last_node = current_node;
    }

    return list_head;
}

int main() {
    struct ListNode* list1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode* list2 = (struct ListNode*)malloc(sizeof(struct ListNode*));

    struct ListNode* current_node = list1;
    current_node->val = 1;
    current_node->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
    current_node = current_node->next;
    current_node->val = 2;
    current_node->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
    current_node = current_node->next;
    current_node->val = 4;
    current_node->next = NULL;

    printf("List1--------------------------\n\r");
    current_node = list1;
    while (current_node != NULL) {
        printf("%d\n\r", current_node->val);
        current_node = current_node->next;
    }

    current_node = list2;
    current_node->val = 1;
    current_node->next = (struct ListNode*)malloc(sizeof(struct ListNode*));
    current_node = current_node->next;
    current_node->val = 3;
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

    printf("Sorted-------------------------\n\r");
    current_node = mergeTwoLists(list1, list2);
    while (current_node != NULL) {
        printf("%d\n\r", current_node->val);
        current_node = current_node->next;
    }

    return 0;
}