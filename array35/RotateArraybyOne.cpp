#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int i=0,j=arr.size()-1;
        
        while(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            
        }
        
    }
};