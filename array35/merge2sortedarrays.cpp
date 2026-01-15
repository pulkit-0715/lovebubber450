#include<iostream>
#include<vector>
using namespace std;
void swap(int *a,int *b){

}
void mergeArrays(vector<int>& arr1, vector<int>& arr2){

    int i=0,j=0;
    while(true)
    {
        if(arr1[i]<arr2[j])
        {
            swap(&arr1[1],&arr2[j]);
            i++;
        }
    }

}
int main()
{
    vector<int> arr1 = {1, 4, 5};
    vector<int> arr2 = {2, 3, 6, 7};;
    ///sorted[1,2,3] [4,5,6,7]
    mergeArrays(arr1,arr2);
}
