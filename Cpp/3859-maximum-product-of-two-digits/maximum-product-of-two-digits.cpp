class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0;
        int ans = 0;

        while (n > 0) {
            int dig = n % 10;
            ans = max(ans, dig * maxi);
            maxi = max(maxi, dig);
            n /= 10;
        }

        return ans;
    }
};