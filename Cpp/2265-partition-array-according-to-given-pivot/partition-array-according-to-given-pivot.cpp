class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        for(auto i: nums) {
            if(i < pivot) ans.push_back(i);
        }

        int i = ans.size();

        for(auto it: nums) {
            if( it == pivot) ans.push_back(it);
        }

        for(auto it: nums) {
            if( it > pivot) ans.push_back(it);
        }
        
        // sort(ans.begin() + i , ans.end());
        return ans;
    }
};