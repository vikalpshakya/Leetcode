class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = 1e9, maxi = -1, g = 0;
        for(auto it: nums) {
            mini = min(mini,it);
            maxi = max(maxi,it);

            g = __gcd(mini,maxi);
        }

        return g;
    }
};