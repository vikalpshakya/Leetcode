class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        map<char,int> freq, used;
        for(auto it: s) freq[it]++;

        string ans = "";

        for(int i = 0; i < n; i++) {

            char ch = s[i];

            if(used[ch] > 0 ){      // this char is already used in our ans
                freq[ch]--;
                continue;
            }

            while(!ans.empty()) {
                if(ans.back() >= ch && freq[ans.back()] > 0) {
                    used[ans.back()]--;
                    ans.pop_back();
                } 
                else break;
            }

            used[ch]++;
            freq[ch]--;
            ans += ch;

        }

        return ans;
    }
};