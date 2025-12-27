void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;  
}

void sort012(int arr[], int n) {
    // code here
    int low=0,mid=0,high=n-1;
    
    
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(&arr[low],&arr[mid]);
            low++;
            mid++;
        }
       else if(arr[mid]==1){
           mid++;
       }
       else
       {
           swap(&arr[mid],&arr[high]);
           high--;
           
       }
    }
}
