class Solution {
public:
    map<int,int>same = {{1,1},{0,0},{8,8}};
    map<int,int>diff = {{2,5},{5,2},{6,9},{9,6}};
    
    bool isValid(int n) {
        bool isSame = true;
        while(n > 0) {
            int dig = n % 10;
            if(same.find(dig) == same.end() && diff.find(dig) == diff.end()) 
                return false;
            if(diff.find(dig) != diff.end()) isSame = false;

            n /= 10;
        }
        return !isSame;
    }

    int rotatedDigits(int n) {
        int ans = 0;

        for(int i = 1; i <= n; i++) {
            ans += isValid(i);
        }
        return ans;
    }
};