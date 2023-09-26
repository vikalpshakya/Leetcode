class Solution {
public:

// Time complexity: O(n), Space complexity: O(1)

    void reverseString(vector<char>& s) {
        int start = 0, end = s.size()-1;
        while(start < end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};
