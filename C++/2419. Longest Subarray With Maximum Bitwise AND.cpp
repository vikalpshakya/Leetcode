// Time complexity: O(n), Space complexity: O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int maxi = *max_element(nums.begin(),nums.end());
       int freq = 0;
       int count = 0;
       for(int i = 1; i < nums.size()+1; i++){
           if(nums[i-1] == maxi){
               freq ++;
               count = max(count,freq);
           }
           else
               freq = 0;
       } 
       return count;
    }
};
