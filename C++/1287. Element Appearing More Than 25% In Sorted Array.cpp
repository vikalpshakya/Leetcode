class Solution {
public:

    // Time complexity: O(n), Space complexity: O(1) 

    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int num = n/4;
        for(int i = 0; i < n; i++){
            if(arr[i] == arr[i+num])
                return arr[i];
        }
        return 0;
    }
};
