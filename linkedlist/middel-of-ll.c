
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head) {

    struct ListNode* i=head;
    struct ListNode* j=head;

    while(j!=NULL && j->next!=NULL)
    {
        i=i->next;
        j=j->next->next;
    }
    return i;
    
}