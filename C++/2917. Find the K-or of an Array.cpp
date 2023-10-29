class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int n = nums.size();
        // if(n == k)return 0;
        int ans = 0;
        
        for(int i = 0; i < 32; i++){
            int count = 0;
            for(int j = 0; j < nums.size(); j++){
                int e = nums[j];
                if(e >> i & 1){
                    count++;
                }
            }
            if(count >= k) {
                ans+= pow(2,i);
            }
        }
        return ans;
    }
};
