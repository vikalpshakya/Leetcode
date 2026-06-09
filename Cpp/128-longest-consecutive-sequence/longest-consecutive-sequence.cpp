class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto it : nums)
            mp[it] = 1;

        int ans = 0;

        for (auto [value, isPresent] : mp) {
            int currLen = 1;
            int num = value;

            while (mp.find(num - 1) != mp.end()) {
                currLen += mp[num - 1];
                mp.erase(num - 1);
                num--;
            }

            mp[value] = currLen;
            ans = max(ans, currLen);
        }

        return ans;
    }
};