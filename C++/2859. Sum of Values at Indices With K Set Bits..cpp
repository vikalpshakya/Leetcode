class Solution {
public:
 // Time complexity: O(n), Space complexity: O(1)

    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for(int i =0; i < nums.size(); i++){
            if(__builtin_popcount(i) == k){
                sum+=nums[i];
            }
        }
        return sum;
    }
};
