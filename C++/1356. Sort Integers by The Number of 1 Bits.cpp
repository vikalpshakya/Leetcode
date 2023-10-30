class Solution {

// TC : O(NLOGN), SC: O(1)

    static bool cmp(int s , int t){
        int s1 = __builtin_popcount(s);
        int t1 = __builtin_popcount(t);
        if(s1 == t1) return s < t;
        return s1 < t1;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};
