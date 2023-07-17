// Time complexity O(max(m.n)) , space O(1) 
//   m and n are the size of respective strings 

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string Word ;
        int size = max(word1.size(), word2.size());
        for( int i = 0 ; i < size ; i++){
            if (i < word1.size())
                Word += word1[i];
            if (i < word2.size())
                Word += word2[i];
            }
            return Word ;
        
