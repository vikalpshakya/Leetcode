class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0;
        int right = 0;
        int step = 0;
        for(char i : moves){
            if(i == 'L'){
                left++;
            }
            else if(i == 'R'){
                right++;
            }
            else step++;
        }
        return max(left,right)-min(left,right)+step;
    }
};
// TC O(N) SC O(1)
