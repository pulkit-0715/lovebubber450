#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* segregate(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* zeroHead = malloc(sizeof(struct Node));
    struct Node* oneHead = malloc(sizeof(struct Node));
    struct Node* twoHead = malloc(sizeof(struct Node));

    zeroHead->next = NULL;
    oneHead->next = NULL;
    twoHead->next = NULL;

    struct Node* zero = zeroHead;
    struct Node* one = oneHead;
    struct Node* two = twoHead;

    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == 0) {
            zero->next = temp;
            zero = temp;
        } else if (temp->data == 1) {
            one->next = temp;
            one = temp;
        } else {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    zero->next = (oneHead->next != NULL) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;

    struct Node* newHead = zeroHead->next;

    free(zeroHead);
    free(oneHead);
    free(twoHead);

    return newHead;
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

        if (head == NULL)
            head = node;
        else
            tail->next = node;

        tail = node;
    }

    head = segregate(head);

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
