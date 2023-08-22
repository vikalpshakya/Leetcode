// Time complexity O(logn) 
// Space complexity O(1) 

class Solution {
    public:
        int firstIndex(vector<int>& arr, int target){
            int n = arr.size();
            int start = 0;
            int end = n - 1;
            int possibleans = n; // -1
            while(start <= end){
                int mid = (start + end) / 2;
                    if(arr[mid] >= target){
                        possibleans = mid;
                        end = mid - 1;
                    }
                    else{
                        start = mid + 1;
                    }
            }
            return possibleans;
        }

        int lastIndex(vector<int>& arr, int target){
            int n = arr.size();
            int start = 0;
            int end = n - 1;
            int possibleans = n; // -1
            while(start <= end){
                int mid = (start + end) / 2;
                if(arr[mid] > target){
                possibleans = mid;
                end = mid - 1;
                }
                else{
                start = mid + 1;
                }
            }
            return possibleans;
        }

        vector<int> searchRange(vector<int>& nums, int target) {
            int first = firstIndex(nums, target);
            int n = nums.size();
            if(first == n or nums[first] != target){
            return {-1, -1};
            }
            int last = lastIndex(nums, target);
            return {first, last - 1};
        }
};
