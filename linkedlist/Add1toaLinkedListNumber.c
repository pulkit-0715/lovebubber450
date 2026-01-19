#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->next = NULL;
    return node;
}

int helper(struct Node* temp) {
    if (temp == NULL)
        return 1;

    int carry = helper(temp->next);

    if (carry == 0)
        return 0;

    temp->data += 1;

    if (temp->data < 10)
        return 0;

    temp->data = 0;
    return 1;
}

struct Node* addOne(struct Node* head) {
    int carry = helper(head);

    if (carry) {
        struct Node* nn = newNode(1);
        nn->next = head;
        return nn;
    }

    return head;
}
