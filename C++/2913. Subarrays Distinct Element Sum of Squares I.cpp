// Time complexity: O(n^3) Space complexity: O(n) // 

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int res= 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                set<int>ans;
                for(int k = i; k <= j; k++){
                    ans.insert(nums[k]);
                }
                int n = ans.size();
                res += pow(n,2);
            }
        }
        return res;
    }
};
