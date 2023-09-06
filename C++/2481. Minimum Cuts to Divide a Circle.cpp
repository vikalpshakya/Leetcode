class Solution {
public:

/*
Here the trick is, if there are even no. slices required then it can be achieved by n/2 cuts
where as if there are odd no. of slices require then it can be done by only cutting it n times
Note : corner case - for we need to get 1, slice we don't hv to cut it, so ans will be zero for n = 1

*/

    int numberOfCuts(int n) {
        if( n == 1) return 0;
        if(n%2 == 0) return n/2;
        else return n;
    
    }
};
