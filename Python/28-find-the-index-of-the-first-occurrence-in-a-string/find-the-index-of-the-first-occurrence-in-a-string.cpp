class Solution {
public:
    int strStr(string full, string sub) {
        int n = full.size();
        int m = sub.size();

        for(int i = 0; i < n - m + 1; i++){
            string str = full.substr(i,m);
            if(str == sub) return i;
        }

        return -1;
    }
};