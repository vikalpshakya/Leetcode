//  TC O(N*M)  SC O(1) 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& input) {
        vector<int>ans;
        int top = 0;
        int left = 0;
        int right = input[0].size()-1;
        int buttom = input.size()-1;

        while ( top <= buttom && left <=  right){

            for ( int i = left ; i <= right ; i++){
            ans.push_back(input[top][i]);
            }   top ++ ;

            for ( int i = top ; i<= buttom;i++){
            ans.push_back(input[i][right]) ;
            }  right--;

            if ( top <= buttom) {
                for ( int i = right ; i >= left ; i--) {
                ans.push_back(input[buttom][i]);
                }   buttom-- ;
            }

            if ( left <=right) {
                for (int i = buttom; i >= top; i--) {
                ans.push_back(input[i][left] );
                }   left++;
            }
        }
        return ans;
    }
};
