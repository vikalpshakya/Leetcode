class Solution {
public:

    void decomp(int x, map<int,int>&mp) {
        string val = to_string(x);
        int num = 0;
        for(int i = 0; i < val.size(); i++) {
            int dig = val[i] - '0';
            num *= 10;
            num += dig;

            mp[num]++;
        }
    }

    int digits(int x) {
        return to_string(x).size();
    }
    
    int longestCommonPrefix(vector<int>& v1, vector<int>& v2) {
        map<int,int>m1,m2;

        for(int i = 0; i < v1.size(); i++) {
            decomp(v1[i],m1);
        }
        for(int i = 0; i < v2.size(); i++) {
            decomp(v2[i],m2);
        }

        int ans = 0;

        for(auto it: m1) {
            if(m2[it.first]) ans = max(ans,it.first);
        }

        return ans > 0 ? digits(ans) : 0;
    }
};