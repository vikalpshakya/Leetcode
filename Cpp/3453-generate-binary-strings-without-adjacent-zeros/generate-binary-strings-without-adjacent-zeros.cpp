class Solution {
public:
    int N;

    void solve(vector<string>& ans, string temp) {
        if (temp.size() == N) {
            ans.push_back(temp);
            return;
        }

        if (temp.empty() || temp.back() == '1') {
            solve(ans, temp + '0');
        }
        solve(ans, temp + '1');
    }
    
    vector<string> validStrings(int n) {
        N = n;
        vector<string> ans;

        solve(ans, "");
        return ans;
    }
};