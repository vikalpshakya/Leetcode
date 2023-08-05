//  T.C O(N)  S.C O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.length()-1;
        if(s.length()==1){
            if(s[0]==' ') return 0;
            else return 1;
        }
        while(true){
            if(s[i]==' ')i--; 
               
            if(s[i]!=' '){
                len++;
                if(i==0) return len;
                i--;
                if(s[i]==' ') return len;
                    
            }
        }
    }
};
