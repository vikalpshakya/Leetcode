class Solution {
public:
    int longestSubstr(string s, int k, char ch) {

        int head = -1, tail = 0;
        int n = s.size();

        int ans = k;

        while (tail < n) {
            while (head + 1 < n && (k > 0 || s[head + 1] == ch)) {
                head++;
                if (s[head] != ch)
                    k--;
            }

            ans = max(ans, head - tail + 1);

            if (s[tail] != ch) k++;
            tail++;
        }

        return ans;
    }

    int characterReplacement(string s, int k) {
        int ans = 0;

        for (int i = 0; i <= 25; i++) {
            char ch = i + 'A';
            ans = max(ans, longestSubstr(s, k, ch));
        }

        return ans;
    }
};