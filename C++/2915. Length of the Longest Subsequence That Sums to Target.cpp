class Solution {
// ---Recursive -----//

    int solve(vector<int>&nums,int t, int i){
        if(t == 0) return 0;
        if(i >= nums.size() ) return INT_MIN;
        int take = 0;
        if(nums[i] <= t) return 1 + solve(nums, t - nums[i] , i + 1);
        int notTake = solve(nums,t , i+1);
        return max(take,notTake);
    }

// ----Memoised ------//

//    Time complexity: O(n), Space complexity: O(t*n)  // 

    int mem(vector<int>&nums, int t , int i, vector<vector<int>>&dp){
        if(t == 0) return 0;
        if(i >= nums.size() || t < 0 ) return INT_MIN;
        if(dp[t][i] != -1) return dp[t][i];
        int take = INT_MIN;
        if(nums[i] <= t) take = 1 + mem(nums, t - nums[i] , i + 1,dp);
        int notTake = mem(nums,t , i+1,dp);
        return dp[t][i] = max(take,notTake);
    }
    int solve_mem(vector<int>& nums, int target){
        vector<vector<int>>dp(target+1 , vector<int>(nums.size()+1, -1));
        return mem(nums,target,0,dp);
    }
    
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int ans = solve_mem(nums,target);
        if(ans < 0 )return -1;
        return ans;
    }
};
