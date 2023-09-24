class Solution {
public:

// Time complexity: O(s1 + s2), where s1 is the length of string s, and s2 is the length of string t

    bool isSubsequence(string s, string t) {
        int s1 = s.size();
        int s2 = t.size();
        int i = 0, j = 0;
        while(i < s1 && j < s2){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }
        if(i == s1) return true;
        return false;
    }
};
