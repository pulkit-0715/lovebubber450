#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* solve(struct Node* head, int* maxVal) {
    if (head == NULL)
        return NULL;

    head->next = solve(head->next, maxVal);

    if (head->data < *maxVal) {
        return head->next;
    }

    *maxVal = head->data;
    return head;
}

struct Node* compute(struct Node* head) {
    int maxVal = 0;
    return solve(head, &maxVal);
}
