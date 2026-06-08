class Solution {
public:

    // TWO PASS Solution

    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n = nums.size();

        int idx = 0, pivotCnt = 0;

        vector<int>ans(n,pivot);

        for(auto i: nums) {
            if(i < pivot) ans[idx++] = i;
            else if(i == pivot) pivotCnt++;
        }

        for(auto i: nums) {
            if(i > pivot){
                ans[idx + pivotCnt] = i;
                idx++;
            }
        }

        return ans;
    }
};