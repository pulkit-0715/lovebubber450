#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct MinHeap {
    struct Node** arr;
    int size;
};

void swap(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

void heapifyDown(struct MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < h->size && h->arr[l]->data < h->arr[smallest]->data)
        smallest = l;
    if (r < h->size && h->arr[r]->data < h->arr[smallest]->data)
        smallest = r;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

void heapifyUp(struct MinHeap* h, int i) {
    int parent = (i - 1) / 2;
    if (i && h->arr[i]->data < h->arr[parent]->data) {
        swap(&h->arr[i], &h->arr[parent]);
        heapifyUp(h, parent);
    }
}

void push(struct MinHeap* h, struct Node* node) {
    h->arr[h->size] = node;
    heapifyUp(h, h->size);
    h->size++;
}

struct Node* pop(struct MinHeap* h) {
    struct Node* root = h->arr[0];
    h->size--;
    h->arr[0] = h->arr[h->size];
    heapifyDown(h, 0);
    return root;
}

struct Node* mergeKLists(struct Node** lists, int K) {
    struct MinHeap h;
    h.arr = malloc(K * sizeof(struct Node*));
    h.size = 0;

    for (int i = 0; i < K; i++)
        if (lists[i])
            push(&h, lists[i]);

    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (h.size) {
        struct Node* curr = pop(&h);
        tail->next = curr;
        tail = tail->next;
        if (curr->next)
            push(&h, curr->next);
    }

    return dummy.next;
}
