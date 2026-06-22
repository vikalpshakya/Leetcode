class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int arr[26] = {0};

        for(char ch: text) arr[ch - 'a']++;
        arr['l' - 'a'] /= 2;
        arr['o' - 'a'] /= 2;
        
        int ans = 1e4;
        string str = "balloon";

        for(int i = 0; i < str.size(); i++) {
            char ch = str[i];
            ans = min(ans, arr[ch - 'a']);
        }

        return ans;
    }
};