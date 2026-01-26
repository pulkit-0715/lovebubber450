#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;
};

struct Node* merge(struct Node* list1, struct Node* list2) {
    struct Node* dummy = malloc(sizeof(struct Node));
    dummy->data = -1;
    dummy->next = NULL;
    dummy->bottom = NULL;

    struct Node* res = dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            res->bottom = list1;
            list1 = list1->bottom;
        } else {
            res->bottom = list2;
            list2 = list2->bottom;
        }
        res = res->bottom;
        res->next = NULL;
    }

    if (list1 != NULL)
        res->bottom = list1;
    else
        res->bottom = list2;

    return dummy->bottom;
}

struct Node* flatten(struct Node* root) {
    if (root == NULL || root->next == NULL)
        return root;

    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* prev = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &m);

        struct Node* columnHead = NULL;
        struct Node* columnPrev = NULL;

        for (int j = 0; j < m; j++) {
            struct Node* node = malloc(sizeof(struct Node));
            scanf("%d", &node->data);
            node->next = NULL;
            node->bottom = NULL;

            if (columnHead == NULL)
                columnHead = node;
            else
                columnPrev->bottom = node;

            columnPrev = node;
        }

        if (head == NULL)
            head = columnHead;
        else
            prev->next = columnHead;

        prev = columnHead;
    }

    head = flatten(head);

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->bottom;
    }

    return 0;
}
