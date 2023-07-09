 // Time complexity = O(n) , space complexity O(1)
 // LOGIC : 1.xor of any two equal number is 0 .
 //         2.xor of 0 and x = x 
 //          so we will keep finding xor of all elements nd ulimately we will get the number which is only present once . 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int Xor=0;
        for( int i =0 ; i < nums.size();i++){
            Xor = Xor^nums[i];
        }
        return Xor ; 
    }
};
