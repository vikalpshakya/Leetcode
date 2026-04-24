class Solution {
public: 
    int n,m;

    int delR[4] = {1,0,-1,0};
    int delC[4] = {0,-1,0,1};

    bool isValid(int r, int c) {
        return r < n && r >= 0 && c < m && c >= 0;
    }

    vector<vector<int>>colorGrid(int N, int M, vector<vector<int>>&source) {
        int numZeros = N*M;
        n = N, m = M;

        vector<vector<int>>grid(n,vector<int>(m,0));

        sort(source.begin(), source.end(), 
            [](vector<int>&a, vector<int>&b) {
                return a[2] > b[2];
            }
        );
        
        queue<pair<int,int>>q;
        for(auto it: source) {
            int i = it[0], j = it[1], val = it[2];
            q.push({i,j});  

            numZeros--;
            grid[i][j] = val;
        }
        
        while(numZeros && !q.empty()) {

            int row = q.front().first, col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int newR = delR[i] + row;
                int newC = delC[i] + col;

                if(isValid(newR,newC) && grid[newR][newC] == 0){
                    grid[newR][newC] = grid[row][col];
                    numZeros--;

                    q.push({newR,newC});
                }
            }

        }

        return grid;
    }
};