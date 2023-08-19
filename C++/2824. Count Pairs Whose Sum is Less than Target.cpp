// Time complexity O(N^2) , Space complexity O(N)
class Solution {
public:
    int countPairs_help(vector<int>&nums , int target , int start){
        if(start>=nums.size()) return 0;
        int count = 0;
        for(int i = start+1 ; i < nums.size() ; ++i){
            if(nums[start]+nums[i] < target) count++;
        }
        return count + countPairs_help(nums,target,start+1);
    }
    int countPairs(vector<int>& nums, int target) {
        return countPairs_help(nums,target,0);
    }
};

