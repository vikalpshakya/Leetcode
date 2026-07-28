class Solution {
public:
    string smallestPalindrome(string str) {
        map<char, int> mp;
        for (auto it : str)
            mp[it]++;

        int n = str.size();

        vector<char> ans(n);

        int s = 0, r = n - 1;

        for (auto it : mp) {

            char ch = it.first; 
            int fr = it.second;

            if (fr % 2 == 1) {
                ans[n/2] = ch;
                fr--;
            }
            while (fr != 0 && s < r) {
                ans[s] = ch;
                ans[r] = ch;
                s++;
                r--;
                fr -= 2;
            }
        }
        
        string res = "";
        for(auto it: ans) res+= it;

        return res;
    }
};

// a -> 2
// b -> 3

// abbba

