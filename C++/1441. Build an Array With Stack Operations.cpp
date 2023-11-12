class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int range = 1;
        int i = 0;
        while(i < target.size() && range <= n){
            ans.push_back("Push");
            if(target[i] == range){
                range++;
                i++;
            }
            else{
                ans.push_back("Pop");
                range++;
            }
        }
        return ans;
    }
};
