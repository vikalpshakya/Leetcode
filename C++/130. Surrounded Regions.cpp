// Time complexity: O(n*m), Space complexity: O(n*m)
class Solution {
private:
    bool isBoundary(int row, int col, int n , int m){
        if(row == 0 || col == 0 || row == n-1 || col == m-1)
            return true;
        return false;
    }

    bool isValid(int row, int col, int n, int m){
        if(row >= 0 && row < n && col >= 0 && col < m) 
            return true;
        return false;
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isBoundary(i,j,n,m) && board[i][j] == 'O'){
                    visited[i][j] = true;
                    q.push({i,j});
                }
            }
        }

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, -1, 0, +1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(isValid(nRow,nCol,n,m) && board[nRow][nCol] == 'O' && !visited[nRow][nCol]){
                    visited[nRow][nCol] = true;
                    q.push({nRow,nCol});
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};







