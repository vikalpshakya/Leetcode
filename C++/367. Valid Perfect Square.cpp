static auto speed=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
};

// Time complexity:O(logN)
// Space complexity: O(1)

class Solution {
public:
    bool isPerfectSquare(int num) {
      long long l = 1, r = num;
        while(l <= r) {
            long long m = (l + r) / 2;
            if(m*m > num) r = m-1;
            else if(m*m < num) l = m+1; 
            else return true;
        }  
        return false;
    }
};
