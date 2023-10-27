class Solution {
// ----------------APPROACH 1 ----------------//
// -----Time complexity: O(n^3), Space complexity: O(n)[recursive stack] ------//

    bool isPalindrome(string &str, int i, int j){
        if(i >= j) return true;
        if(str[i] == str[j]) return isPalindrome(str,i+1,j-1);
        return false;       
    }
    string solve1(string s) {
        int n = s.size();
        int maxLen = INT_MIN;
        int start = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(s,i,j)){
                    if((j-i+1) > maxLen){
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
// ----------------APPROACH 2 ----------------//
// -----Time complexity: O(n^3), Space complexity: O(n)[recursive stack] ------//

    int dp[1001][1001];


    bool isPalindrome2(string &str, int i, int j){
        if(i >= j) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(str[i] == str[j]) return dp[i][j] = isPalindrome2(str, i+1, j-1);

        return dp[i][j] = 0;       
    }
    string solve2(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        int maxLen = INT_MIN;
        int start = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome2(s,i,j)){
                    if((j-i+1) > maxLen){
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }


   public:
    string longestPalindrome(string s) {
        // return solve1(s);
        return solve2(s);

    }
};
