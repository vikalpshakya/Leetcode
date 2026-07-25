class Solution {
public:
    int n,m;
    int delR[4] = {1,0,0,-1};
    int delC[4] = {0,1,-1,0};
    bool isValid(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }
    void dfs(int r, int c,vector<vector<char>>& grid,vector<vector<bool>>&vis ) {
        vis[r][c] = true;
        for(int i = 0;i < 4; i++) {
            int newR = r + delR[i];
            int newC = c + delC[i];

            if(isValid(newR,newC) && !vis[newR][newC] && grid[newR][newC] == '1') dfs(newR,newC,grid,vis); 
        }
    }

    int numIslands(vector<vector<char>>& grid) {
         n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int comp = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j< m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i,j,grid,vis);
                    comp++;
                }
            }
        }
        return comp;
    }
};