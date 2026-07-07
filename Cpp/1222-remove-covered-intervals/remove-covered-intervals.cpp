class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& vec) {
        sort(vec.begin(), vec.end());
        int n = vec.size();

        int overLapping = 0;

        for (int i = 0; i < n; i++) {
            int l = vec[i][0], r = vec[i][1];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (vec[j][0] <= l && vec[j][1] >= r) {
                    overLapping++;
                    break;
                }
            }

        }

        return n - overLapping;
    }
};
