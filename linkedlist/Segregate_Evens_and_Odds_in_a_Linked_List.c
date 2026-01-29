#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* divide(struct Node* head) {
    if (head == NULL)
        return head;

    struct Node *evenStart = NULL, *evenEnd = NULL;
    struct Node *oddStart = NULL, *oddEnd = NULL;

    struct Node* curr = head;

    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            if (evenStart == NULL) {
                evenStart = curr;
                evenEnd = curr;
            } else {
                evenEnd->next = curr;
                evenEnd = evenEnd->next;
            }
        } else {
            if (oddStart == NULL) {
                oddStart = curr;
                oddEnd = curr;
            } else {
                oddEnd->next = curr;
                oddEnd = oddEnd->next;
            }
        }
        curr = curr->next;
    }

    if (evenStart == NULL)
        return oddStart;

    evenEnd->next = oddStart;

    if (oddEnd != NULL)
        oddEnd->next = NULL;

    return evenStart;
}
