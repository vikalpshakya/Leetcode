class Solution {
public:
    int findMin(vector<int>& vec) {
        /*
        monotonic pattern:- 

        left segment will always be greater than last element of vec
        right segment will always be lesser than last element of vec
        [ 0 , 0 , 0 , 0 , 1 , 1 , 1]
        0 = vec[i] > last element
        1 = vec[i] < last element
        min val of vec == first element in right segment
            => ie ..first '1' in the reduced array , 
        */

        int n = vec.size() , last = vec.back();
        int ans = 1e5;
        int s = 0, e = n-1;

        while(s <= e) {
            int mid = (s + e) / 2;
            if(vec[mid] <= last) {
                ans = min(ans , vec[mid]);
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }
};