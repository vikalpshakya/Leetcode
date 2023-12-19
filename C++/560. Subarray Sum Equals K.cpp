// Time complexity: O(n), Space complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pre(n);
        int count = 0;
        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = nums[i] + pre[i-1];
        }

        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            if(pre[i] == k) count++;
            int toFind = pre[i] - k;
            if(mp.find(toFind) != mp.end()){
                count+= mp[toFind];
            }
            mp[pre[i]]++;
        }
        return count++;
    }
};
