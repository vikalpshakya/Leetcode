class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& v1, vector<int>& v2) {
        map<int,int>mp;

        int n = v1.size();
        vector<int>ans(n,0);

        for(int i = 0; i < n; i++){
            if(mp[v1[i]] == 1) ans[i]++;
            mp[v1[i]]++;
            if(mp[v2[i]] == 1) ans[i]++;
            mp[v2[i]]++;


            ans[i] += i > 0 ? ans[i-1] : 0;
        }
        return ans;
    }
};