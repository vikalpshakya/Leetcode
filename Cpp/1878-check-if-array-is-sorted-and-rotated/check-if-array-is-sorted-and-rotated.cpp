class Solution {
public:
    bool check(vector<int>& vec) {
        int pivot = 0, n = vec.size();

        for(int i = 0; i < n - 1; i++) {
            if(vec[i] > vec[i+1]) {
                pivot = i+1;
                break;
            }
        }

        int count = 1;

        while(count < n){
            // cout << pivot % n << " " << (pivot + 1) % n << endl;

            if(vec[pivot % n] > vec[(pivot + 1) % n]) return false;
            
            pivot++;
            count++;
        }

        return true;
    }
};