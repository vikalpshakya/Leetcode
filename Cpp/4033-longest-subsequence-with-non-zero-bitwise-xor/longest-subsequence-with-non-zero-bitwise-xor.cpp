class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int nonZ = 0;
        for(auto it: nums) {
            nonZ += it > 0;
            ans ^= it;
        }
        if(ans) return n;
        else if(nonZ) return n - 1;
        return 0;
    }
};

