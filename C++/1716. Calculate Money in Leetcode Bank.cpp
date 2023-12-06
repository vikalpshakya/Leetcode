class Solution {
// Time complecity: O(n) 
public:
    int totalMoney(int n) {
        int sum = 0, add = 0, st = 1;
        for(int i = 1; i <= n; i++){
            sum+= (add+st++);
            if(i%7 == 0) {add++; st = 1;}
        }
        return sum;
    }
};
