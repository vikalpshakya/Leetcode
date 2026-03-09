// Time complexity: O(N+2E), Space complexity: O(E)

class Solution {
private:
    bool dfs(vector<vector<int>>& adj, vector<int>& color, int sv , int col){
        color[sv] = col;
        for(auto i : adj[sv]){
            if(color[i] == -1){
                bool ans = dfs(adj, color, i, !col);
                if(!ans) return false;
            }
            else if(color[i] == col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>color(n,-1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                bool ans = dfs(adj, color, i , 0);
                if(!ans) return false;
            }
        }
        return true;
    }
};
