#include <stdio.h>

#define MAX 100000

int stack[MAX];
int top = -1;
int mini;

void push(int a) {
    if (top == -1) {
        stack[++top] = a;
        mini = a;
    } else if (a >= mini) {
        stack[++top] = a;
    } else {
        stack[++top] = 2*a - mini;
        mini = a;
    }
}

int isFull(int n) {
    return top == n - 1;
}

int isEmpty() {
    return top == -1;
}

int pop() {
    if (top == -1)
        return -1;

    int t = stack[top--];

    if (t >= mini)
        return t;
    else {
        int realValue = mini;
        mini = 2*mini - t;
        return realValue;
    }
}

int getMin() {
    if (top == -1)
        return -1;

    return mini;
}
