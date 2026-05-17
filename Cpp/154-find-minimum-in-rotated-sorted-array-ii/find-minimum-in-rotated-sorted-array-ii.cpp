class Solution {
public:
    int findMin(vector<int>& vec) {
        /*
    https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/2005756160/

        O(logn) wont be possible coz , there's no monotonic seq here

        */

        return *min_element(vec.begin(),vec.end());
        
    }
};