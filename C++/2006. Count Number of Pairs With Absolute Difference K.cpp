class Solution {

// TC: O(N^2), SC: O(1)//

    int solve1(vector<int>& nums, int k){
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(abs(nums[i] - nums[j]) == k)
                    count++;
            }
        }
        return count;
    }

// TC: O(N), SC: O(N)//

    int solve2(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto i : nums){
            ans += mp[i-k];
            ans += mp[i+k];
            mp[i]++;
        }
        return ans;
    }
    
public:
    int countKDifference(vector<int>& nums, int k) {
        // return solve1(nums,k);
        return solve2(nums,k);
    }
};
