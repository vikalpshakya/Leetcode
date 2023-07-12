// Time complexity O(nlogn) , space complexity O(n)

class Solution {
public:
    void merge2array(vector<int>&arr,int s , int e){ // merging two sorted arrays 
    vector<int>output(e-s+1);
    
    int mid  = (s+e)/2;
    int i = s , j = mid+1 , k=0;
    while (i<=mid && j<= e){
        if( arr[i]<arr[j]){
            output[k++]=arr[i++];
        }
        else{
            output[k++]=arr[j++];
        }
    }
    while ( i<=mid){
        output[k++]=arr[i++];
    }
    while ( j<=e){
        output[k++]=arr[j++];
        }

        for (int x = s; x <= e; x++) {
          arr[x] = output[x - s];
        }
}
void mergeSort(vector<int>& arr, int s, int e) {   //merge sort 
    if (s>=e) {
        return  ;
    }
    int mid = (s+e)/2;
    mergeSort(arr,s, mid);
    mergeSort(arr,mid+1, e);  
    merge2array(arr,  s, e);

    }
  vector<int> sortArray(vector<int>& nums) { // main function -------------- 
        int start = 0;
        int end = nums.size()-1;
        mergeSort(nums,start,end);
        return nums;
    }
};
