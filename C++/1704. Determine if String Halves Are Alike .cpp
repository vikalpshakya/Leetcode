class Solution {
private:

    bool isVowel(char ch) {

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' 
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' )
            return true;
        return false;
    }

public:

    bool halvesAreAlike(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(i < n/2 && isVowel(s[i]))
                count++;
            else if(isVowel(s[i]))
                count--;
        }

        return count == 0;
    }
};
