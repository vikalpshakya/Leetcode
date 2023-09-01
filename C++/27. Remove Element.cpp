class Solution {
public:
// -------Approach 1 ------------//

//  Time complexity O(n) , Space O(n)
    int removeElement1(vector<int>& nums, int val) {
        vector<int>ans ;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                ans.push_back(nums[i]);
            }
        }
        nums.assign(ans.begin(),ans.end());
        return ans.size();
    }

 // -----------Approach 2------//

//  Time complexity O(n) , Space O(1)
    int removeElement(vector<int>& nums, int val) {
        int ans = 0 ;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[ans++] = nums[i];
            }
        }
        return ans;
    }
};

