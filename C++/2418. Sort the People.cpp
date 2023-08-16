// Time Complexity O(n) , Space Complexity O(n) 

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& h) {
        int n=names.size();
        vector<pair<int,string>>p;
        for(int i=0;i<n;i++){
            p.push_back({h[i],names[i]});
        }
        sort(p.rbegin(),p.rend());
        vector<string>res;
        for(int i=0;i<n;i++){
            res.push_back(p[i].second);
        }
       return res;
    }
};
