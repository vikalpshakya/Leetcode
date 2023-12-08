// Time complexity : O(n*m), Space complexity: O(n*m)

class Solution {
private:
    int bfs(vector<vector<int>>& grid, queue<pair<pair<int,int>,int>>& q,
     vector<vector<bool>>& visited, int delRow[], int delCol[]){
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            time = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow >=0 && nRow < n && nCol >= 0 && nCol < m &&
                 !visited[nRow][nCol] && grid[nRow][nCol] == 1){
                     q.push({{nRow,nCol},time+1});
                     visited[nRow][nCol] = true;
                 }
            }        
        }
        return time;         
     }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;
        // {{row,col},time}
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    visited[i][j] = 2;
                    q.push({{i,j},0});
                }
            }
        }
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        int ans = bfs(grid, q, visited, delRow, delCol);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1)
                    return -1;
            }
        }
        return ans;
    }
};
