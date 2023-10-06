// ----Time complexity: O(n), Space complexity: O(n)-----//

class Solution {
    int solve_memHelp(int n , vector<int>&dp){
        if (n < 0) return -1;
        if(n <= 2) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            int mul = i* solve_memHelp(n-i,dp);
            ans = max(mul,ans);
            dp[n] = ans;
        }
        return ans;
    }
    int solve_mem(int n){
        if(n == 3) return 2;
        vector<int>dp(n+1,-1);
        return solve_memHelp(n,dp);
    }
    int solve_tab(int n){
        vector<int>dp(n+2,1);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for(int i = 4; i <= n; i++){
            int ans = INT_MIN;
          for(int j = 1; j <= i; j++){
            int mul = dp[j] * dp[i-j];
            ans = max(mul,ans);
            // dp[i] = ans;
        }
        // return ans;
        dp[i] = ans; 

        }
        return dp[n];
    }

public:
    int integerBreak(int n) {
        return solve_tab(n);
    }
};
