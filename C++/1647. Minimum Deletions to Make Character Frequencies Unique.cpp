class Solution {
public:
// -----Time complexity: O(n) , Space complexity: O(n) -----//
    int minDeletions(string s) {
        unordered_set<int>st;
        unordered_map<char,int>mp;
        for(int i = 0; i < s.length(); i++)
            ++mp[s[i]];

        int del = 0;
        for(auto i : mp){
            int count = i.second;
            while(count > 0 && st.find(count) != st.end()){
                count--;
                del++;
            }
            st.insert(count);
        }
        return del;
    }
};
