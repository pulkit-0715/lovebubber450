#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    struct Node* dummy = newNode(0);
    struct Node* tail = dummy;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data == temp2->data) {
            tail->next = newNode(temp1->data);
            tail = tail->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->data < temp2->data) {
            temp1 = temp1->next;
        } else {
            temp2 = temp2->next;
        }
    }

    return dummy->next;
}

int main() {
    struct Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(6);

    struct Node* head2 = newNode(2);
    head2->next = newNode(4);
    head2->next->next = newNode(6);
    head2->next->next->next = newNode(8);

    struct Node* result = findIntersection(head1, head2);

    while (result != NULL) {
        printf("%d ", result->data);
        result = result->next;
    }

    return 0;
}
