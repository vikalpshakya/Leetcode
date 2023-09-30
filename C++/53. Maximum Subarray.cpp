// Time complexity: O(n), Space complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int maxi = nums[0];
        for(int i = 1; i < nums.size(); i++ ){
            curr = max(nums[i],curr+nums[i]);
            maxi = max({maxi,curr,nums[i]});
            if(curr < 0){
                curr = 0;
            }
        }
        return maxi;
    }
};
