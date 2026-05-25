class Solution {
public:
/*
        for(int i = n - 2; i >= 0; i--) {
            if(pre[i] > suff[i+1]) {
                ans[i] = ans[i+1];
            }
            else ans[i] = pre[i];
        }

        pre[i] = max element in range (0, i)
        suff[i + 1] = min element in range(i+1, n)
        res[i] = max possible value attained on i

        if at any point, If pre[i] > suff[i+1] :-
        it means my answer can lie in the range (i+1, .. n). [since it can go back and then again forward , thereby increase our reach]
        => ans would be res[i+1] , which is the best possible ans

*/


    vector<int> maxValue(vector<int>& vec) {
        int n = vec.size();

        vector<int>pre(n,-1), suff(n,1e9);

        pre[0] = vec[0];
        suff[n-1] = vec[n-1];

        for(int i = 1; i < n; i++) {
            pre[i] = max(pre[i-1], vec[i]);
        }

        for(int i = n - 2; i >= 0; i--) {
            suff[i] = min(suff[i+1], vec[i]);
        }

        vector<int>ans(n, -1);
        ans[n-1] = pre[n-1];

        for(int i = n - 2; i >= 0; i--) {
            if(pre[i] > suff[i+1]) {
                ans[i] = ans[i+1];
            }
            else ans[i] = pre[i];
        }

        return ans;
    }
};