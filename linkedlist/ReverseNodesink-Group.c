#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* findKth(struct ListNode* head, int k) {
    while (head != NULL && k > 1) {
        head = head->next;
        k--;
    }
    return head;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* temp = head;
    struct ListNode* prevGroup = NULL;

    while (temp != NULL) {
        struct ListNode* kth = findKth(temp, k);
        if (kth == NULL) {
            if (prevGroup != NULL)
                prevGroup->next = temp;
            break;
        }

        struct ListNode* nextGroup = kth->next;
        kth->next = NULL;

        struct ListNode* newHead = reverse(temp);

        if (temp == head)
            head = newHead;
        else
            prevGroup->next = newHead;

        prevGroup = temp;
        temp = nextGroup;
    }

    return head;
}
