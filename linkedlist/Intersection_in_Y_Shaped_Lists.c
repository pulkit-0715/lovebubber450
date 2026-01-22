#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* newNode(int x) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = x;
    temp->next = NULL;
    return temp;
}

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (headA == NULL || headB == NULL)
        return NULL;

    struct ListNode* pA = headA;
    struct ListNode* pB = headB;

    while (pA != pB) {
        if (pA == NULL)
            pA = headB;
        else
            pA = pA->next;

        if (pB == NULL)
            pB = headA;
        else
            pB = pB->next;
    }

    return pA;
}

int main() {
    struct ListNode* common = newNode(8);
    common->next = newNode(10);

    struct ListNode* headA = newNode(3);
    headA->next = newNode(7);
    headA->next->next = common;

    struct ListNode* headB = newNode(99);
    headB->next = newNode(1);
    headB->next->next = common;

    struct ListNode* result = getIntersectionNode(headA, headB);

    if (result != NULL)
        printf("%d\n", result->val);
    else
        printf("No Intersection\n");

    return 0;
}
