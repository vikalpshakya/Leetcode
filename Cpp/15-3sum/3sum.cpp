class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (auto it : nums)
            cout << it << " ";
        cout << endl;

        for (int i = 0; i < n - 2; i++) {
            int val1 = nums[i];

            int l = i + 1, r = n - 1;

            while (l < r) {
                int left = nums[l], right = nums[r];

                if (left + right + val1 == 0) {
                    ans.push_back({val1, nums[l], nums[r]});
                    while (l < r && r - 1 >= 0 && nums[r - 1] == right)
                        r--;
                    while (l < r && l + 1 < n && nums[l + 1] == left)
                        l++;
                    l++, r--;
                }
                int sum = -val1;

                if (nums[l] + nums[r] > sum)
                    r--;
                else if (nums[l] + nums[r] < sum)
                    l++;
            }

            while (i < n - 2 && val1 == nums[i + 1])
                i++;
        }

        return ans;
    }
};