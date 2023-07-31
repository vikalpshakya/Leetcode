// Time complexity O(n^2) , space complexity O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        if(nums.size()<3) return result;
        sort(nums.begin(),nums.end());
        for( int i = 0; i < nums.size(); i++){
            int a = nums[i] ;
            int target = -a;
            int low = i + 1, high = nums.size() -1;
            while(low < high){
                if(nums[low]+nums[high]==target){
                    result.push_back({nums[i],nums[low],nums[high]});
                    while(low<high&&nums[low]==nums[low+1]) low++;
                    while(low<high&&nums[high]==nums[high-1]) high--;
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high]<target) low++;
                else high--;
            }
            while(i+1<nums.size()&&nums[i+1]==nums[i]) i++;
        }
        return result;
    }
};
