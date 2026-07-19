class Solution {
public:
    string smallestSubsequence(string s) {
        string ans = "";

        int n = s.size();
        vector<int>cnt(26,0) , vis(26,0);

        for(auto it: s) cnt[it - 'a']++;

        for(auto it: s) {
            cnt[it - 'a']--;

            // we have already assigned the most optimal place for that char
            if(vis[it - 'a']) continue; 

            while(!ans.empty() && (ans.back() > it && cnt[ans.back() - 'a'])) {
                vis[ans.back() - 'a'] = 0;
                ans.pop_back();
            }

            vis[it - 'a'] = 1;
            ans.push_back(it);
        }

        return ans;
    }








};