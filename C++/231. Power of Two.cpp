class Solution {
public:  
/* Naive Approach, Time complexity : O(logn) , space complexity : O(1) */
    bool isPowerOfTwo_brute(int n) {
        if(n==1||n==2){
            return true;
        }
        if(n%2!=0||n==0){
            return false;
        }
        int ans=1;
        while(n%2==0 && n!=2){
            if(n%2==0){
                n=n/2;
                ans=n;
                if(n==0){
                    break;
                }
            } 
        }
        if(ans%2==0){
            return true;
        }
        return false;      
    }

/* Approach-2, Using Bit Manipulation 
	represent a number in bits, .count() will return the count number of 1's	
  bitset::count() is an inbuilt STL in C++ which returns the number of set bits in the binary representation of a number
  Time complexity O(1) , Space complexity O(1) */

    bool isPowerOfTwo_bitset(int n){
        if(n<0) return false;
      
        bitset<32> bin(n);
        return bin.count()==1 ? true:false ; //using tertiary operator 
    }

    bool isPowerOfTwo(int n) {
        return isPowerOfTwo_bitset(n);
      

    }
};
