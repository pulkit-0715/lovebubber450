#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        
          int n = arr.size();
    if (n == 1) return 0;


    sort(arr.begin(), arr.end());

    int res = arr[n - 1] - arr[0];
    for (int i = 1; i < n; i++) {
        
        if (arr[i] <k) continue;

        int small = min(arr[0] + k, arr[i] - k);
        int big = max(arr[i - 1] + k, arr[n - 1] - k);

        res = min(res, big - small);
    }
        
        return res;
        
        
    }
};
