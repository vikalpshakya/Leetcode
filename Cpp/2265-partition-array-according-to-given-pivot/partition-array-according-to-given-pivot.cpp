class Solution {
public:
    // ONE PASS Solution

    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n = nums.size();

        vector<int> ans(n, pivot);

        int l = 0, r = n - 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot)
                ans[l++] = nums[i];
                
            if (nums[n - i - 1] > pivot) {
                ans[r--] = nums[n - i - 1];
            }
        }

        return ans;
    }
};