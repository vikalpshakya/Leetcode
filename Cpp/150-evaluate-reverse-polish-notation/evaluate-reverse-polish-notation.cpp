class Solution {
public:
    int evalRPN(vector<string>& vec) {
        stack<int> st;

        for (auto s: vec) {
            if (isdigit(s.back())) {   // can't compare with s[0] , bcs of cases like -1
                int num = stoi(s); 
                st.push(num);
            }
            else {
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();

                if (s[0] == '+')
                    st.push(n1 + n2);
                else if (s[0] == '*')
                    st.push(n1 * n2);
                else if (s[0] == '/')
                    st.push(n1 / n2);
                else
                    st.push(n1 - n2);
            }
        }

        return st.top();
    }
};