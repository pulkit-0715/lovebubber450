#include <stdio.h>

int setBits(int n) {
    int count = 0;

    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }

    return count;
}

int main() {
    int n = 11;   // example input
    printf("%d\n", setBits(n));
    return 0;
}
