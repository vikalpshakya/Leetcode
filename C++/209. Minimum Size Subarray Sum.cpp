// Time complexity: O(n), Space complexity: O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, sum = 0; // two pointers set at the starting of the array
        int minLen = INT_MAX;

        while(i < n && j < n){
            sum += nums[j];
            if(sum >= target){ // we have found a large window[subarray] whose sum >= target
                while(i <= j && sum >= target){ // now we will reduce the size of window as much as possible
                    minLen = min(minLen, j-i+1);
                    sum -= nums[i++];
                }
            }
            j++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
