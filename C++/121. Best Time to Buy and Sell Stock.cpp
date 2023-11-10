class Solution {
public:
// TC: O(n)
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mn = INT_MAX;
        for(int ele: prices){
            mn = min(mn, ele);
            int curProfit = ele - mn;
            ans = max(ans, curProfit);
        }
        return ans;
    }
};
