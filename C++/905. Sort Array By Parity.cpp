class Solution {
    vector<int> sortArrayByParity_app1(vector<int>& nums) {
      // TC:O(n), SC: O(n)
        vector<int>ans;
        for(auto i : nums){
            if(i%2 == 0){
                ans.push_back(i);
            }
        }
        for(auto i : nums){
            if(i%2!=0){
                ans.push_back(i);
            }
        }
        return ans;
    }
  // TC:O(n), SC: O(1)
    vector<int> sortArrayByParity_app2(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        while(j<n){
            if(nums[j]%2==0) swap(nums[i++],nums[j++]);
            else j++;
        }
        return nums;
    }
  // TC:O(nlogN), SC: O(1)
    static bool cmp(int a, int b) {
        return a % 2 < b % 2;
    }

    vector<int> sortArrayByParity_app3(vector<int>&nums){
        sort(nums.begin(),nums.end(),cmp);
        return nums;
    }

    public:
    vector<int> sortArrayByParity(vector<int>& nums){
        return sortArrayByParity_app3(nums);
    }

};
