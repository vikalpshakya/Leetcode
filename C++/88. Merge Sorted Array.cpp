// Time complexity = O(m+n) , space complexity = O(m+n) 
// where m and n are size of nums1 and nums2[excluding 0's] 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>output(m+n);
        int i=0 , j=0 , k=0 ;
        while(i<m&&j<n){
            if(nums1[i]<nums2[j]){
                output[k++] = nums1[i++];
            }
            else{
                output[k++]=nums2[j++];
            }
        }
        while(i<m){
            output[k++]=nums1[i++];
        }
        while(j<n){
            output[k++]=nums2[j++];
        }
        for( int i =0 ; i<output.size();i++){
            nums1[i]=output[i];
        }
        
    }
};
