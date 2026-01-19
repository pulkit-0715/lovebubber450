#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

#define SIZE 10007

struct HashNode {
    int key;
    struct HashNode* next;
};

struct HashNode* hashTable[SIZE];

int hash(int key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

int exists(int key) {
    int index = hash(key);
    struct HashNode* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->key == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void insert(int key) {
    int index = hash(key);
    struct HashNode* node = (struct HashNode*)malloc(sizeof(struct HashNode));
    node->key = key;
    node->next = hashTable[index];
    hashTable[index] = node;
}

struct Node* removeDuplicates(struct Node* head) {
    struct Node* curr = head;
    struct Node* prev = NULL;

    while (curr != NULL) {
        if (exists(curr->data)) {
            prev->next = curr->next;
        } else {
            insert(curr->data);
            prev = curr;
        }
        curr = curr->next;
    }

    return head;
}
