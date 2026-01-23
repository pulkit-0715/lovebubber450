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

struct Node* findmid(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node* merge(struct Node* left, struct Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    struct Node* dummy = newNode(0);
    struct Node* temp = dummy;

    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    if (left != NULL)
        temp->next = left;
    else
        temp->next = right;

    return dummy->next;
}

struct Node* mergeSort(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* mid = findmid(head);
    struct Node* right = mid->next;
    mid->next = NULL;

    struct Node* left = mergeSort(head);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    struct Node* head = newNode(4);
    head->next = newNode(2);
    head->next->next = newNode(1);
    head->next->next->next = newNode(3);

    head = mergeSort(head);

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    return 0;
}
