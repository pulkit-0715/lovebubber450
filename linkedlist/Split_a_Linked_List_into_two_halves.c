#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Pair {
    struct Node* first;
    struct Node* second;
};

struct Pair splitList(struct Node* head) {
    struct Pair result;
    result.first = NULL;
    result.second = NULL;

    if (head == NULL)
        return result;

    if (head->next == head) {
        result.first = head;
        result.second = head;
        return result;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* head1 = head;
    struct Node* head2 = slow->next;

    slow->next = head1;

    struct Node* tail = head2;
    while (tail->next != head)
        tail = tail->next;

    tail->next = head2;

    result.first = head1;
    result.second = head2;
    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0)
        return 0;

    struct Node* head = NULL;
    struct Node* prev = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* node = malloc(sizeof(struct Node));
        scanf("%d", &node->data);
        node->next = NULL;

        if (head == NULL)
            head = node;
        else
            prev->next = node;

        prev = node;
    }

    prev->next = head;

    struct Pair res = splitList(head);

    struct Node* temp = res.first;
    if (temp) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != res.first);
        printf("\n");
    }

    temp = res.second;
    if (temp) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != res.second);
        printf("\n");
    }

    return 0;
}
