static auto Vikalp = [](){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();
// TC: O(n)
const int mod = 1e9+7;
class Solution {
    long long sum(long long n ){
        return ((n)*(n+1))/2;
    }
public:
    int countHomogenous(string s) {
        long long n = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != s[i+1]) n++;
            else{
                long long count = 1;
                while(i < s.size()){
                    if(s[i] == s[i+1]) count++;
                    else break;
                    i++;
                }
                n+=sum(count) %mod;
            }
        }
        return (int)n%mod;
    }
};
