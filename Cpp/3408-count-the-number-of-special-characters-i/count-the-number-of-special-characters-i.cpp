class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>mp;

        for(auto it: word) {
            mp[it]++;
        }

        int ans = 0;

        for(int i = 0; i <= 26; i++) {
            char small = i + 'a';
            char big   = i + 'A';

            if(mp[small] * mp[big] >= 1) ans++;
        }

        return ans;
        
    }
};