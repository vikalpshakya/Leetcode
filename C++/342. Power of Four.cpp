class Solution {

//    Time complexity: O(logn), Space complexity: O(logn)

    bool solve_rec(int n){
        if(n == 1) return true;
        if(n%4 != 0 || n == 0) return false;
        return solve_rec(n/4);
    }
// Time complexity: O(logn), Space complexity: O(1)

    bool solve_itr(int n){
        if(n==1||n==4) return true;
        
        if(n%4!=0||n==0) return false;
        
        int ans=1;
        while(n%4==0 && n!=4){
            if(n%4==0){
                n=n/4;
                ans=n;
                if(n==0) break; 
            } 
        }
        if(ans%4==0) return true;
        
        return false;   
    } 

public:
    bool isPowerOfFour(int n) {
        // return solve_rec(n);
        return solve_itr(n);
    }
};
