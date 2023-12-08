// Time complexity: O(n*m), Space complexity : O(n*m)

class Solution {
private:
    vector<vector<int>> dfs(vector<vector<int>>& ans, vector<vector<int>>& image, int row, int col,int delRow[], int delCol[], int inColor, int newColor){
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < 4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && ans[nRow][nCol] != newColor && image[nRow][nCol] == inColor)
                dfs(ans, image, nRow, nCol, delRow, delCol,inColor, newColor);
        }
        return ans;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int inColor = image[sr][sc];
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1}; // for calculating the adjacent blocks 
        vector<vector<int>>ans = image;
        dfs(ans, image, sr, sc, delRow, delCol, inColor, newColor);
        return ans;
    }
};
