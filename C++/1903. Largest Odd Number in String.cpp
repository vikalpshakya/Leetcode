// Time complexity: O(n), Space complexity: O(1) 
class Solution {
public:
    string largestOddNumber(string& num) {
        string ans = "";
        for(int i = num.size(); i >= 0; i--){
            if(num[i] & 1) {
              ans+=num.substr(0,i+1);
              return ans;
            }
        }
        return "";
    }
};
