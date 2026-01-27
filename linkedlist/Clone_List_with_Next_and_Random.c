#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* random;
};

struct Node* cloneLinkedList(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* temp = head;

    while (temp != NULL) {
        struct Node* copy = malloc(sizeof(struct Node));
        copy->data = temp->data;
        copy->next = temp->next;
        copy->random = NULL;
        temp->next = copy;
        temp = temp->next->next;
    }

    temp = head;

    while (temp != NULL) {
        if (temp->random != NULL)
            temp->next->random = temp->random->next;
        else
            temp->next->random = NULL;
        temp = temp->next->next;
    }

    struct Node* dummy = malloc(sizeof(struct Node));
    dummy->next = NULL;

    struct Node* res = dummy;
    temp = head;

    while (temp != NULL) {
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }

    struct Node* copyHead = dummy->next;
    free(dummy);

    return copyHead;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* node = malloc(sizeof(struct Node));
        scanf("%d", &node->data);
        node->next = NULL;
        node->random = NULL;

        if (head == NULL)
            head = node;
        else
            tail->next = node;

        tail = node;
    }

    struct Node* copy = cloneLinkedList(head);

    struct Node* temp = copy;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
