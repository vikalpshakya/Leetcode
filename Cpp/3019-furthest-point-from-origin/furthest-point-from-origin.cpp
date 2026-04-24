class Solution {
public:
    int furthestDistanceFromOrigin(string str) {
        int a = 0, b = 0;
        for(auto it: str) {
            a += it == 'L';
            a -= it == 'R';
            b += it == '_';
        }        
        a = abs(a);
        a += b;
        return a;
    }
};