class Solution {

// Time complexity: O(n), Space complexity: O(n)

public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int>s;
        s.push(nums[n-1]);
        int a = INT_MIN;
        for(int i = n-2; i>=0; i--){
            if(nums[i] < a){
                return true;    
            }
            while(!s.empty() && nums[i] > s.top()){
                a  = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};
