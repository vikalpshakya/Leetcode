class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& vec) {
        sort(vec.begin(),vec.end());

        vector<vector<int>>ans;
        int s = vec[0][0] , e = vec[0][1];

        for(int i = 1; i < vec.size(); i++) {
            if(vec[i][0] <= e) {
                e = max(e,vec[i][1]); 
            } else {
                ans.push_back({s,e});
                s = vec[i][0] , e = max(e,vec[i][1]);
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};