class Solution {
public:
// TC: O(n) SC O(n)
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
};
