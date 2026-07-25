class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        vector<bool>v(3000, false);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                v[nums[i]^nums[j]] = true;
            }
        }

        vector<bool>s(3000, false);
        for(int i=0; i<n; i++){
            for(int j=0; j<3000; j++){
                if(v[j]){
                    s[j^nums[i]] = true;
                }
            }
        }

        int ans = 0;
        
        for(int i=0; i<3000; i++){
            if(s[i])
                ans++;
        }
        return ans;
    }
};