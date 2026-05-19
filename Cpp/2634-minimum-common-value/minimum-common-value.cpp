class Solution {
public:

//  move pointer s1 in v1 till it's <= s2 in v2 , and then increase s2 in v2
// TC: O(n+m)

    int getCommon(vector<int>& v1, vector<int>& v2) {
    
        int n = v1.size(), m = v2.size();
        int s1 = 0, s2 = 0;

        while(s1 < n && s2 < m) {

            while(s1 < n-1 && v1[s1] < v2[s2]) s1++;

            if(v1[s1] == v2[s2]) return v1[s1];

            s2++;
        }
        
        return -1;
    }
};