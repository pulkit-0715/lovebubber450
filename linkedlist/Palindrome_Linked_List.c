#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverse(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* newHead = reverse(slow->next);
    struct ListNode* first = head;
    struct ListNode* second = newHead;

    while (second != NULL) {
        if (first->val != second->val) {
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverse(newHead);
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("true");
        return 0;
    }

    int x;
    scanf("%d", &x);

    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = x;
    head->next = NULL;

    struct ListNode* curr = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        curr->next = malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = x;
        curr->next = NULL;
    }

    printf(isPalindrome(head) ? "true" : "false");
    return 0;
}
