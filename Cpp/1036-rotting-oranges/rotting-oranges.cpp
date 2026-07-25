class Solution {
public:
    int n,m;
    int delR[4] = {1,0,0,-1};
    int delC[4] = {0,1,-1,0};

    bool isValid(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        queue<pair<int,int>>q;
        int fresh = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0;
        int ans = 0;

        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto [r,c] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int newR = r + delR[i];
                    int newC = c + delC[i];

                    if(isValid(newR,newC) && grid[newR][newC] == 1) {
                        q.push({newR,newC});
                        grid[newR][newC]= 2;
                    }
                }
            }
            ans++;
        }   

        for(auto it: grid) {
            for(auto i: it) {
                if(i == 1) return -1;
            }
        }

        
        return ans-1;
    }
};