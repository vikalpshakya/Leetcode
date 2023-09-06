class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      // ----Approach 1 ------- // 
      
      // Time complexity: O(nlogN), Space complexity: O(1)
      
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == nums[i+1]) return nums[i];
    }
    return 0;
    }

// ----------Approach 2 ------------// 

    // Time complexity: O(N), Space complexity: O(N)

    unordered_map<int,int>mp;
    for(int i = 0; i < nums.size(); i++){
        ++mp[nums[i]];
    }
    for(auto i : mp){
        if(i.second > 1) return i.first;
    }
    return 0;
    }

};
