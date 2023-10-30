class Solution {
public:

// TC: O(NLOGN), SC: O(1) //

    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int max1 = nums[n-1];
        int max2 = nums[n-2];
        int min1 = nums[0];
        int min2 = nums[1];
        return (max1 * max2) - (min1 * min2);

    }
};
