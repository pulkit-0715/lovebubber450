#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int getKthFromLast(struct Node* head, int k) {
    if (head == NULL)
        return -1;

    struct Node* slow = head;
    struct Node* fast = head;

    for (int i = 0; i < k; i++) {
        if (fast == NULL)
            return -1;
        fast = fast->next;
    }

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}
