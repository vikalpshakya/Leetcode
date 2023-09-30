// Time complexity: O(n! *n), Space complexity: O(n^2)

class Solution {
    bool isSafe(int row, int col , vector<vector<string>> &ans,vector<string> &board , int n){
        int x = row;
        int y = col;
        while(y >= 0){           // checking if queen is there in the row 
            if(board[x][y] =='Q')
                return false;
            y--;
        }
        x = row;
        y = col;
        while(x >= 0 && y>=0 ){
            if(board[x][y] == 'Q')
                return false;
            y--;
            x--;
        }
        x = row;
        y = col;
        while (x < n && y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            y--;
            x++;
        }
        return true;
    }

    void solve(int col , vector<vector<string>> &ans,vector<string> &board , int n) {
        if( col == n){              // base case
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++) {   
                if(isSafe(row, col,ans, board, n)){
                    board[row][col] = 'Q';
                    solve(col+1, ans, board,  n);
                    // bactrack call 
                    board[row][col] = '.';
                }
            }
    }
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<string>board(n,string(n,'.'));
            vector<vector<string>> ans;
            
            solve(0 , ans ,board , n);
            return ans;  
        }
};
