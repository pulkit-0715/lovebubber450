#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* reverse(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* curr = head;
    struct Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    return temp->prev;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0)
        return 0;

    struct Node* head = NULL;
    struct Node* last = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* node = malloc(sizeof(struct Node));
        scanf("%d", &node->data);
        node->next = NULL;
        node->prev = last;

        if (last)
            last->next = node;
        else
            head = node;

        last = node;
    }

    head = reverse(head);

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
