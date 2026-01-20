#include <stdio.h>

void swap(char *a, char *b)
{
    char z = *a;
    *a = *b;
    *b = z;
}

void reverseString(char* s, int sSize)
{
    int i = 0, j = sSize - 1;
    while (i < j)
    {
        swap(&s[i], &s[j]);
        i++;
        j--;
    }
}

int main()
{
    char s[] = {'h','e','l','l','o'};
    int size = 5;

    reverseString(s, size);

    for (int i = 0; i < size; i++)
        printf("%c ", s[i]);

    return 0;
}
