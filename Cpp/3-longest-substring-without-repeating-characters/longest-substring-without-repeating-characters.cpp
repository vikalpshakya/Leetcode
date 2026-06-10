class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();

        map<char, int> mp;

        int head = -1, tail = 0, ans = 0;

        while (tail < n) {

            while (head + 1 < n && mp[s[head + 1]] == 0) {
                head++;
                mp[s[head]]++;
            }
            
            ans = max(ans, (head - tail) + 1);

            if (tail > head)
                head = tail;
            else {
                mp[s[tail]]--;
                tail++;
            }
        }
        return ans;
    }
};
