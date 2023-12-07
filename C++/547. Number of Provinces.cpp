// Time complexity : O(n), Space coplexity: O(n)

class Solution {
    private:
        void bfs(int n, vector<int>adj[], vector<bool>&visited, int sv) {
        queue<int>q;
        q.push(sv);
        visited[sv] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto i : adj[front]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    
   int connectedComp(int n, vector<int>adj[]){
        int count = 0;
        vector<bool>visited(n,false);
        for(int i = 0; i < n; i++){
            if (!visited[i]) {
                bfs(n, adj, visited, i);
                count++;
            }
        }
        return count;
    }

    public:
        int findCircleNum(vector<vector<int>> &edges) {
            int e = edges.size();
            vector<int>adj[e+1]; 
            
            for(int i = 0; i < e; i++){
                for(int j = 0; j < e; j++){
                    if(edges[i][j] == 1 && i != j){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
            return connectedComp(e,adj);
        } 
};
