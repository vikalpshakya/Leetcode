// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

class Solution {
private:
    bool isValid(int row, int col , int n) {
        if(row >= 0 && row < n && col >= 0 && col < n) 
            return true;
        return false;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != grid[n-1][n-1]) return -1;
        if(n == 1) {
            return grid[0][0] == 0 ? 1 : -1;
        }
        vector<vector<int>> distance(n,vector<int> (n, INT_MAX));
        distance[0][0] = 0;
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},0});

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    int delR = row + i;
                    int delC = col + j;
                    if(isValid(delR,delC,n) && grid[delR][delC] == 0) {
                        if(delR == n-1 && delC == n-1) return dis + 2;
                        if( distance[delR][delC] > dis + 1) {
                            distance[delR][delC] = dis + 1;
                            q.push({{delR,delC},dis+1});
                        }
                    }

                } 
            }

        }
        return -1;
    }
};
