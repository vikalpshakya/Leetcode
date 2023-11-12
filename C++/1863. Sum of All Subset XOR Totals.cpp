class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int xorr;
        int n = nums.size();
        for(int i = 0; i < (1<<n); i++){
            xorr = 0;
            for(int j = 0; j < n; j++){
                if( i&(1 << j))  // each 'i' is representing a subsequence of length n and we are
                                // checking for each bit in i. Creating a bitmask
                xorr^=nums[j];
            }
            sum += xorr;
        }
        return sum;
    }
};
