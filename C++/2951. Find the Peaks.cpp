class Solution {
// Tc: O(n), Sc: O(1);
public:
    vector<int> findPeaks(vector<int>& vec) {
        vector<int>ans;
        int count = 0;
        for(int i = 0; i < vec.size()-2; i++){
            if(vec[i] < vec[i+1] && vec[i+1] > vec[i+2])ans.push_back(i+1);
        }
        return ans;
        
    }
};
