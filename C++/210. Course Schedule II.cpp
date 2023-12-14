class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edge) {
        int m = edge.size();
        vector<int>adj[n];
        for(int i = 0; i < m; i++){
            int f = edge[i][0];
            int s = edge[i][1];
            adj[s].push_back(f);
        }
        vector<int>indeg(n,0);

        for(int i = 0; i < n; i++){
            for(auto j: adj[i])
                indeg[j]++;
        }
        
        queue<int>q;
        
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0)
                q.push(i);
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            int front = q.front();  
            q.pop();
            ans.push_back(front);
          
            for(auto i: adj[front]){
                indeg[i]--;
                if(indeg[i] == 0)
                    q.push(i);
            }
        }
    
    if(ans.size() == n) return ans;
    
    return {};

    }
};
