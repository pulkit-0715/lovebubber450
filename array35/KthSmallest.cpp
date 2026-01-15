#include <iostream>
#include <queue>
using namespace std;

using namespace std;

int kthSmallest(int arr[], int n, int k) {
    priority_queue<int> maxHeap;

    // Step 1: Push first k elements
    for (int i = 0; i < k; i++) {
        maxHeap.push(arr[i]);
    }

    // Step 2: Process remaining elements
    for (int i = k; i < n; i++) {
        if (arr[i] < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }

    return maxHeap.top();
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << "Kth smallest element is " << kthSmallest(arr, n, k);
    return 0;
}
