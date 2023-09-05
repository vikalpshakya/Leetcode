class Solution {
public:

// Time compexity: O(n), Space complexity: O(1)

    bool isHappy(int n) {
        while( n != 1 && n > 9){
            int sum = 0;
            while(n > 0){
                int digit = n % 10;
                sum += digit*digit;
                n /= 10;
            }
            n = sum;
        }
        return n == 1 || n == 7;
    }       
};
