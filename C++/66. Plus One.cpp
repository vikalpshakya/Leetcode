//   Time complexity Worst case :- O(n)
//   Space complexity: O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int end = digits.size()-1;
        int start = 0 ;
        while (start <= end) { 
            if ( digits[end] < 9) {
                digits[end] +=1 ;
                break;
            }
            else { 
                digits[end] = 0;
                end--;
            }
        }
            if(digits[start]==0){
                digits.insert(digits.begin(),1);
            }
        return digits ;
    }
};

// APPROACH
//  Traversing on each integer in our vector from the end. If the last number is less than 9 then we just simply add 1 into int and return the remaining vector.
//  Else,  if the last integer is 9, then we would make it 0 and will continue our traversal from behind for the same.
//  In case all elements are 9, then they would be converted into 0, and then we will insert 1 at the beginning of the vector and return it.



