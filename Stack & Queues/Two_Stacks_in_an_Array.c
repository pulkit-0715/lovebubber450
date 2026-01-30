#include <stdio.h>
#include <stdlib.h>

struct twoStacks {
    int *arr;
    int front;
    int tail;
    int size;
};

struct twoStacks* createTwoStacks(int n) {
    struct twoStacks* ts = (struct twoStacks*)malloc(sizeof(struct twoStacks));
    ts->size = n;
    ts->arr = (int*)malloc(n * sizeof(int));
    ts->front = -1;
    ts->tail = n;
    return ts;
}

void push1(struct twoStacks* ts, int x) {
    if (ts->front + 1 < ts->tail) {
        ts->arr[++ts->front] = x;
    }
}

void push2(struct twoStacks* ts, int x) {
    if (ts->front + 1 < ts->tail) {
        ts->arr[--ts->tail] = x;
    }
}

int pop1(struct twoStacks* ts) {
    if (ts->front >= 0) {
        return ts->arr[ts->front--];
    }
    return -1;
}

int pop2(struct twoStacks* ts) {
    if (ts->tail < ts->size) {
        return ts->arr[ts->tail++];
    }
    return -1;
}
