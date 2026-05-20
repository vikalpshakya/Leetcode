class Solution {
public:

    int ones(string str) {
        int one = 0;
        for(auto ch: str) one += ch == '1';
        return one;
    }

    int zeros(string str) {
        int zero = 0;
        for(auto ch: str) zero += ch == '0';
        return zero;
    }

    int dp[601][101][101];

    int rec(vector<string>& strs, int i, int m, int n) {
        if(i == strs.size()) return 0;
        if(m < 0 || n < 0) return 0;

        if(dp[i][m][n] != -1) return dp[i][m][n];

        int pick = 0, notPick = 0;
        int zCount = zeros(strs[i]) , oneCount = ones(strs[i]);

        if( zCount <= m && oneCount <= n) {
            pick = 1 + rec(strs, i+1, m - zCount , n - oneCount);
        }
        notPick = rec(strs, i+1, m, n);

        return dp[i][m][n] = max(pick,notPick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        memset(dp, -1, sizeof(dp));
        return rec(strs, 0, m, n);

    }
};