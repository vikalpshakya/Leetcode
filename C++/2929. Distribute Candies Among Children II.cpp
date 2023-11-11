class Solution {
public:
    long long solve(int n){
        
        return 1LL* n * (n-1) / 2;
    }
    int distributeCandies(int n, int limit) {
        if(n  > 3 * limit){
            return 0;
        }
        long long ans = solve(n+2);
        if(n>limit){
            ans -= 3 * solve(n - limit + 1);
        }
        if(n - 2 >= 2 * limit){
            ans +=  3 * solve(n - 2 * limit); 
        }
        return ans;
    }
};
