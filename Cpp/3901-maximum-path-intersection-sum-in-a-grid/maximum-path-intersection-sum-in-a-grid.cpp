class Solution {
public:
    int maxSubarrayAtLeastTwo(vector<int>& a) {
        int n = a.size();

        int kadane = a[0];   // best subarray ending at previous index
        int ans = INT_MIN;

        for (int i = 1; i < n; i++) {
            int withLen2 = a[i - 1] + a[i];
            int extend = kadane + a[i];

            ans = max(ans, max(withLen2, extend));

            kadane = max(a[i], kadane + a[i]);
        }

        return ans;
    }

    int maxScore(vector<vector<int>>& grid) {
        int ans = -1e9;

        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            int maxRowSum = maxSubarrayAtLeastTwo(grid[i]);
            ans = max(ans, maxRowSum);
        }

        for (int col = 0; col < m; col++) {

            vector<int> columnElements;

            for (int row = 0; row < n; row++) {
                columnElements.push_back(grid[row][col]);
            }

            int maxColSum = maxSubarrayAtLeastTwo(columnElements);

            ans = max(ans, maxColSum);
        }

        // for case where there's only one point of intersection
        // for that the element should'nt be on the boundary

        for(int i = 1; i < n-1; i++) {
            for(int j = 1; j < m-1; j++) ans = max(ans, grid[i][j]);
        }

        return ans;
    }
};