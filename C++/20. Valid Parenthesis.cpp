// Time complexity O(n) , Space O(n) 
class Solution {
public:
    bool isValid(string s) {
        if(!s.size())
           return true;

      stack<char> st;
      for(int i=0; i<s.size(); i++) {
          if(s[i] == '}') {
              if(st.empty()) return false;
              else{
                  if(st.top() == '{') st.pop();
                  else return false;
              }
          }
          else if(s[i] == ']') {
              if(st.empty()) return false;
              else{
                  if(st.top() == '[') st.pop();
                  else return false;
              }
          }
          else if(s[i] == ')') {
              if(st.empty()) return false;
              else{
                  if(st.top() == '(') st.pop();
                  else return false;
              }
          }
          else
              st.push(s[i]);
      }   
      return st.empty() ? true : false;
  }
};
