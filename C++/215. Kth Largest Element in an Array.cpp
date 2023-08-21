// Time complexity O(n(log k))
// Space complexity O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> >pq;
        for( int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }
        int j = k;
        while( j < nums.size()){
            if(nums[j] > pq.top()){
                pq.pop();
                pq.push(nums[j]);
            }
            j++;
        }
        return pq.top();
    }
};
