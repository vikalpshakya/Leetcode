class Solution {
public:
    bool isPerfect(int x) {
        int root = sqrt(x);
        return root * root == x;
    }
    bool judgeSquareSum(int c) {
        for(int i = 0; i <= sqrt(c); i++) {
            long long x = i * i;
            if(isPerfect(c - x)) return true;
        }
        return false;
    }
};