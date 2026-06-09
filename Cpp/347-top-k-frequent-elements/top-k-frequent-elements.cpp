class Solution {
public:
    // TC: (n log K)

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto it: nums) mp[it]++;

        priority_queue<pair<int,int>>pq;

        for(auto [val, freq] : mp) {
            pq.push({-freq,val});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int>ans;

        while(!pq.empty()) {
            int top = pq.top().second;
            ans.push_back(top);
            pq.pop();
        }

        return ans;
    }
};