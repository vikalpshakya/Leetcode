class Solution {
public:
    bool subMatrix(vector<vector<char>>& vec, int n, int m) {
        map<char, int> mp;

        for (int i = n; i < n + 3; i++) {
            for (int j = m; j < m + 3; j++) {
                if (vec[i][j] != '.') {
                    mp[vec[i][j]]++;
                    if (mp[vec[i][j]] > 1)
                        return false;
                }
            }
        }
        return true;
    }

    bool vertical(vector<vector<char>>&vec, int j) {
        map<char, int> mp;
        for(int i = 0; i < 9; i++) {
            if (vec[i][j] != '.') {
                    mp[vec[i][j]]++;
                    if (mp[vec[i][j]] > 1)
                        return false;
            }
        }
        return true;
    }

    bool horizontal(vector<vector<char>>&vec, int i) {
        map<char, int> mp;
        for(int j = 0; j < 9; j++) {
            if (vec[i][j] != '.') {
                    mp[vec[i][j]]++;
                    if (mp[vec[i][j]] > 1)
                        return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool isValid = true;

        for(int i = 0; i < 9; i++) {
            isValid &= vertical(board,i);
            isValid &= horizontal(board,i);
        }

        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                isValid &= subMatrix(board,i,j);
            }
        }

        return isValid;
    }
};