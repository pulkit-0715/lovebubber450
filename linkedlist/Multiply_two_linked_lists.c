#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

struct Node {
    int data;
    struct Node* next;
};

long long multiplyTwoLists(struct Node* first, struct Node* second) {
    long long n1 = 0, n2 = 0;

    while (first != NULL) {
        n1 = (n1 * 10 + first->data) % MOD;
        first = first->next;
    }

    while (second != NULL) {
        n2 = (n2 * 10 + second->data) % MOD;
        second = second->next;
    }

    return (n1 * n2) % MOD;
}
