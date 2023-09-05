class Solution {
public:

// Time complexity: O(n) , Space complexity: O(1)

    int addDigits(int n) {
        int sum = 0;
        while(n > 9){
            while(n > 0){
                int digit = n%10;
                sum+=digit;
                n = n/10;
            }
            n = sum;
            sum = 0;
        }
        return n;
    }
};
