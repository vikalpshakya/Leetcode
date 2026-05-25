class Solution {
public:

    int n, d;
    int dp[1001];
    vector<int>vec;

    int rec(int i) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int back = 1, frwd = 1;

        for(int j = i + 1; j <= i + d && j < n; j++) {
            if(vec[i] > vec[j]) 
                frwd = max(frwd , 1 + rec(j));
            else break;
        }

        for(int j = i - 1; (j >= 0) && (j >= i - d); j--) {
            if(vec[i] > vec[j]) 
                back = max(back, 1 + rec(j));
            else break;
        }

        return dp[i] = max(back,frwd);
    }

    int maxJumps(vector<int>& arr, int D) {
        n = arr.size();
        d = D;
        vec = arr;

        memset(dp,-1,sizeof(dp));

        int ans = 1;

        for(int i = 0; i < n; i++) {
            ans = max(ans, rec(i));
        }

        return ans;
    }
};