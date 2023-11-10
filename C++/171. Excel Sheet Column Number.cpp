lass Solution {
public:
    int titleToNumber(string str) {
        int ans = 0;
        int n = str.length();
        for(int i = 0; i < n; i++){
            ans = (ans * 26) + (str[i] - 'A' + 1);
        }
        return ans;
    }
};
