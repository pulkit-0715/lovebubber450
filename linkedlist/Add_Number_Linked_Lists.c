#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insert_digit(struct Node** head, struct Node** tail, int digi) {
    struct Node* temp = newNode(digi);
    if (*head == NULL) {
        *head = temp;
        *tail = temp;
    } else {
        (*tail)->next = temp;
        *tail = temp;
    }
}

struct Node* add(struct Node* first, struct Node* second) {
    int carry = 0;
    struct Node* anshead = NULL;
    struct Node* anstail = NULL;

    while (first != NULL || second != NULL || carry != 0) {
        int val = 0;
        if (first != NULL) val += first->data;
        if (second != NULL) val += second->data;

        int sum = carry + val;
        insert_digit(&anshead, &anstail, sum % 10);
        carry = sum / 10;

        if (first != NULL) first = first->next;
        if (second != NULL) second = second->next;
    }
    return anshead;
}

struct Node* addTwoLists(struct Node* head1, struct Node* head2) {
    head1 = reverse(head1);
    head2 = reverse(head2);

    struct Node* ans = add(head1, head2);
    ans = reverse(ans);

    while (ans != NULL && ans->data == 0 && ans->next != NULL)
        ans = ans->next;

    return ans;
}

int main() {
    struct Node* head1 = newNode(4);
    head1->next = newNode(5);

    struct Node* head2 = newNode(3);
    head2->next = newNode(4);
    head2->next->next = newNode(5);

    struct Node* result = addTwoLists(head1, head2);

    while (result != NULL) {
        printf("%d", result->data);
        result = result->next;
    }
    printf("\n");

    return 0;
}
