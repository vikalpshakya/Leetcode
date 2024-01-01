class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count = 0;
        int m = g.size(), n = s.size();
        int i = 0 , j = 0;
        for(; i < n && j < m;){
            if(s[i] >= g[j]) {
                count++;
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        return count;
    }
};
