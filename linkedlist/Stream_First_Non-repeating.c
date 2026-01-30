#include <stdio.h>
#include <stdlib.h>

#define MAX 26

char* FirstNonRepeating(char* A) {
    int freq[MAX] = {0};

    char* q = (char*)malloc(100005 * sizeof(char));
    int front = 0, rear = 0;

    char* result = (char*)malloc(100005 * sizeof(char));
    int idx = 0;

    for (int i = 0; A[i] != '\0'; i++) {
        char ch = A[i];
        int pos = ch - 'a';

        freq[pos]++;
        q[rear++] = ch;

        while (front < rear && freq[q[front] - 'a'] > 1) {
            front++;
        }

        if (front < rear)
            result[idx++] = q[front];
        else
            result[idx++] = '#';
    }

    result[idx] = '\0';
    return result;
}
