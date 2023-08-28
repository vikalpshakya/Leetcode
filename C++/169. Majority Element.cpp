class Solution {
public:
// ----------APPROACH 1 ------------//

// Time complexity O(n) Space complexity O(n)

    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++){
            ++map[nums[i]];
        }
        int count = 0;
        int maj_element;
        unordered_map<int, int> :: iterator it = map.begin();
        while(it != map.end()){
            if(it->second > n/2){
               maj_element = it->first;
            }
            ++it;
        }
        return maj_element;
    }


// ---------APPROACH 2 --------------------//

// Time complexity O(nLogn) , Space complexity O(1) 

    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};













  
