//  Time complexity O(n) , Space complexity O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0 ;
        set<int>s;  //  Set only carries unique value in sorted order 
        
        for(i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
       nums.assign(s.begin(),s.end());
        return s.size() ;
        
    }
};
