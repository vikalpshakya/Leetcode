class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool>vis(n+1,false);

        queue<int>q;
        q.push(start);

        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            vis[idx] = true;
            if(arr[idx] == 0) return true;

            int prev = idx - arr[idx];
            int forw = idx + arr[idx];

            if(prev >= 0 && !vis[prev]) q.push(prev);
            if(forw < n && !vis[forw]) q.push(forw);
        }
        return false;
    }
};