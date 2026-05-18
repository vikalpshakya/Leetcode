class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>adj;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            adj[arr[i]].push_back(i);
        }

        vector<bool>vis(n,false);

        queue<pair<int,int>>q; // {idx , steps}
        q.push({0,0});
        vis[0] = true;

        while(!q.empty()) {
            int idx = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(idx == n-1) return steps;

            if(idx - 1 >= 0 && !vis[idx - 1]) {
                q.push({idx-1, steps+1});
                vis[idx-1] = true;
            } 
            if(idx + 1 < n && !vis[idx + 1]) {
                q.push({idx+1, steps+1});
                vis[idx+1] = true;
            } 
            for(auto it: adj[arr[idx]]) {
                if(!vis[it]) {
                    q.push({it, steps+1});
                    vis[it] = true;
                } 
            }
            adj[arr[idx]].clear();
        }

        return n - 1;
    }
};