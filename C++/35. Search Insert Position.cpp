class Solution {
public:
// ---------Approach 1 ----------// 

// Time complexity: O(n), Space complexity: O(1)

    int searchInsert(vector<int>& nums, int target) {
        int index ;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                index = i; 
                return index;
            }
            else if(nums[i] > target) {
                index = i;
                return index;
            }
        }
        return index;
    }
};
