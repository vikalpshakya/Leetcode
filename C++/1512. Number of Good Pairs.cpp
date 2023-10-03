class Solution {
public:
// Time complexity: O(n^2), Space complexity: O(1)
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size() && i!=j; j++){
                if(nums[i] == nums[j])
                    count ++;
            }
        }
        return count;
    }
};
