class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        int n = words.size();
        string ans = "";

        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 0; j < words[i].size(); j++) {
                int idx = words[i][j] - 'a';
                sum = (sum + weights[idx]) % 26;
            }
            cout << sum << endl;
            ans.push_back('a' + (26 - sum) - 1);
        }
        return ans;
    }
};