class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        
        while (j < n) {
            int temp = nums[j];
            mp[temp]++;
            if (mp[temp] > k) {
                while (mp[temp] > k && i <= j) {
                    int x = nums[i];
                    mp[x]--;
                    i++;
                }
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};
