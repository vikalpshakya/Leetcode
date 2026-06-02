class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n = ls.size(), m = ws.size();

        int ans = 1e9;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {
                
                if(ls[i] < ws[j]) {
                    int time = ls[i] + ld[i];
                    int timeDiff = max(0, ws[j] - time);

                    ans = min(ans, time + timeDiff + wd[j]);
                }
                else {
                    int time = ws[j] + wd[j];
                    int timeDiff = max(0, ls[i] - time);

                    ans = min(ans, time + timeDiff + ld[i]);
                }
            }
        }

        return ans;
    }
};