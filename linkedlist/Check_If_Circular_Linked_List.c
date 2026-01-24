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

int isCircular(struct Node* head) {
    if (head == NULL)
        return 1;

    struct Node* temp = head->next;

    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    if (isCircular(head))
        printf("Circular\n");
    else
        printf("Not Circular\n");

    return 0;
}
