class Solution {
public:
// Time complexity O(n) , Space complexity O(n)

    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int>st;
        int longest = 1;
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        for(auto it : nums){
            if(st.find(it-1) == st.end()){
                int x = it;
                int count = 1;
                while(st.find(x+1) != st.end()){
                    count ++;
                    x++;
                }
                longest = max(longest,count);
            }
        }
        return longest;
    }
};
