/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>

int main(){
    
    return 0;
}
 int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0]; 
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    
    int** result = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);

    int idx = 0;

    result[0] = (int*)malloc(sizeof(int) * 2);
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;

    for (int i = 1; i < intervalsSize; i++) {
        
        if (intervals[i][0] <= result[idx][1]) {
            result[idx][1] = 
                (intervals[i][1] > result[idx][1]) ? 
                 intervals[i][1] : result[idx][1];
        } 
        else {
            idx++;
            result[idx] = (int*)malloc(sizeof(int) * 2);
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx] = 2;
        }
    }

    *returnSize = idx + 1;
    return result;
}