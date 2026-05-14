class Solution {
public:
    bool isGood(vector<int>& vec) {
       int n = vec.size() - 1;

       if(n == 0) return false;

       for(int i = 1; i <= n ; i++) {
            int count = 0;

            for(int j = 0; j < vec.size(); j++) {
                if(vec[j] == i) count++;
            }

            if(i == n) {
                if(count != 2) return false;
            }
            if(i != n) {
                if(count != 1) return false;
            }

       } 
       return true;
    }
};