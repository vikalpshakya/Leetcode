class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();

        int head = -1, tail = 0;
        int startIdx = -1, ans = n;

        map<int, int> freq;
        for (auto it : t)
            freq[it]++;

        int reqChar = freq.size();

        while (tail < n) {
            while (head + 1 < n && reqChar > 0) {
                head++;
                freq[s[head]]--;
                if (freq[s[head]] == 0)
                    reqChar--;
            }

            int substrSize = head - tail + 1;
            if (reqChar == 0 && substrSize <= ans) {
                startIdx = tail;
                ans = substrSize;
            }

            freq[s[tail]]++;
            if (freq[s[tail]] > 0)
                reqChar++;
            tail++;
        }

        if (startIdx == -1)
            return "";

        return s.substr(startIdx, ans);
    }
};