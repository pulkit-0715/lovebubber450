#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* removeDuplicates(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* i = head;

    while (i != NULL && i->next != NULL) {
        if (i->data == i->next->data) {
            i->next = i->next->next;
        } else {
            i = i->next;
        }
    }

    return head;
}
