// TC O(N)   SC O(1)
class Solution {
public:
    void Reverse(vector<int>&nums , int start , int end){
        reverse( nums.begin() + start , nums.begin()+ end);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        Reverse(nums , 0 , n-k);
        Reverse(nums , n-k , n);
        Reverse(nums , 0 , n);
    }
};
