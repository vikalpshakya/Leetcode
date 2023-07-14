class Solution {
public:

//   ************* ITERATIVE APPROACH **********  //
//      Time complexity O(logn) Space complexity O(1)   //

    bool isPowerOfThree_iterative(int n) {
        if(n==1||n==3){
            return true;
        }
        if(n%3!=0||n==0){
            return false;
        }
        int ans=1;
        while(n%3==0 && n!=3){
            if(n%3==0){
                n=n/3;
                ans=n;
                if(n==0){
                    break;
                }
            } 
        }
        if(ans%3==0){
            return true;
        }
        return false;   
    }
// ************* RECURSIVE APPROAACH **********  //
//      Time complexity O(logn) Space complexity O(logn)   //

    bool isPowerOfThree_rec(int n){
        if(n==1||n==3) return true;
        if(n<1) return false ;
        if(n%3!=0)return false;
        return isPowerOfThree_rec(n/3);
         } 

//  --------- MAIN FUNCTION ---------
    bool isPowerOfThree(int n){
        return isPowerOfThree_rec(n);
        // return isPowerOfThree_iterative(n);
    }
};




