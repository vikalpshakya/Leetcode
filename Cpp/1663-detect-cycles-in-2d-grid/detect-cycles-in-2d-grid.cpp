class Solution {
public:

    bool isCycle = false;
    vector<vector<bool>>vis;
    vector<vector<char>>grid;
    int n,m;

    int delR[4] = {1,0,-1,0};
    int delC[4] = {0,1,0,-1};

    bool isValid(int r, int c) {
        return (r >= 0 && r < n && c < m && c >= 0);
    }

    void dfs(int r, int c, int prevR, int prevC) {
        vis[r][c] = true;

        for(int i = 0; i < 4; i++) {
            int newR = delR[i] + r;
            int newC = delC[i] + c;

            if(isValid(newR, newC) && grid[r][c] == grid[newR][newC]) {
                if(vis[newR][newC] == true && (newR != prevR && newC != prevC)) isCycle = true;
                else if(vis[newR][newC] == false) dfs(newR, newC, r, c);
            }
        }
    }

    bool containsCycle(vector<vector<char>>& _grid) {
        grid = _grid;
        n = grid.size(), m = grid[0].size();

        vis.assign(n,vector<bool>(m,false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j])
                    dfs(i, j, -1, -1);
            }
        }

        return isCycle;
    }
};