class Solution {
    // Time complexity: O(n), Space complexity: O(n)
    int app1(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        int e = edges.size();
        for(int i = 0; i < e; i++){
            int f = edges[i][0];
            int s = edges[i][1];
            mp[f]++; mp[s]++;
        }
        for(auto i : mp) {
            if(i.second == e) return i.first;
        }
        return 0;
    }
    // Time complexity: O(1), Space complexity: O(1)
    int app2(vector<vector<int>>& ed){
        if(ed[0][0] == ed[1][0] || ed[0][0] == ed[1][1])
            return ed[0][0];
        return ed[0][1];
    }
public:
    int findCenter(vector<vector<int>>& edges) {
        return app2(edges);
    }
};
