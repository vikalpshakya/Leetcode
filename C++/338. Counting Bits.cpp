class Solution {
public:
// ---------Appproach 1 -------//

// TC:  O(n * log(n)) SC O(1) [since returntype of function is vector so its ouput vector wouldn't be considered in space count]

    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int count = 0;
            int x = i;
            while(x!=0){
                count+=(x&1);
                x=x>>1;
            }
            ans.push_back(count);
        }
        return ans;
    }
//     -------APPROACH 2------------    //

//     Time complexity: O(n), Space complexity: O(1)
        vector<int> dp(n+1);

        if(n == 0) return dp;
        dp[0] = 0;
        for(int i = 1; i < n+1; i++){
            if(i%2 != 0){
                dp[i] = dp[i/2] + 1;
            }
            else 
                dp[i] = dp[i/2];
        }
        return dp;
    }
};
