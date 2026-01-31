#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *arr;
    int top;
    int size;
};

struct Stack* createStack(int size) {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->size = size;
    s->top = -1;
    s->arr = (int*)malloc(size * sizeof(int));
    return s;
}

void push(struct Stack* s, int x) {
    if (s->top < s->size - 1) {
        s->arr[++s->top] = x;
    }
}

int pop(struct Stack* s) {
    if (s->top >= 0) {
        return s->arr[s->top--];
    }
    return -1;
}

void deleteMidUtil(struct Stack* s, int k) {
    if (k == 0) {
        pop(s);
        return;
    }

    int temp = pop(s);
    deleteMidUtil(s, k - 1);
    push(s, temp);
}

void deleteMid(struct Stack* s) {
    int k = s->top / 2;
    deleteMidUtil(s, k);
}
