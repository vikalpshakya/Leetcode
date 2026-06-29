class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        map<string,int>mp;
        int n = word.size();

        for(int i = 0; i < n; i++){
            string curr = "";
            for(int j = i; j < n; j++) {
                curr += word[j];
                mp[curr] = 1;
            }
        }

        int ans = 0;

        for(auto it: patterns) {
            ans += mp[it];
        }

        return ans;
    }
};