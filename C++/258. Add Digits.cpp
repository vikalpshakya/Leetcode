class Solution {
public:
    // -------Approach 1 --------- // 

/*  Time complexity ~ O(1) [number of operations = number of digits in a number , which is approx O(1)
    Space complexity: O(1)                                                                                */

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
// -------Approach 2 ------ // 

// Time complexity: O(1), Space complexity: O(1) 

    int addDigits(int num) {
        if ( num == 0 ) return 0;
        else if (num % 9 == 0) return 9;
        else return num % 9;
    }
};

/*
  EXPLAINATION : https://leetcode.com/problems/add-digits/solutions/1754049/easy-o-1-explanation-with-example/
  
If you look at the digital root ( the thing this question asks viz - sum untill the sum is single digit)
  for the first 100 digits.
  
-You can probably notice the cycle, that is the digit num starts from 0 and ends at 9

-If you think about it, it is obvious as every time we are adding one to the modulus

-Thus the ans is the remainder of the division of the number with 9

-Unless remainder is 0 then the ans is 9

-We need to be carefull of the 0 case, where the ans is 0 */
