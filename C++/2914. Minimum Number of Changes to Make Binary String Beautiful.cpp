// Time complexity : O(n) , Space complexity: O(1) 

class Solution {
public:
    int minChanges(string s) {
        int count = 0;
        
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] != s[i+1]) count ++ ;    
            i++;
        
        }
        return count ;
    }
};
