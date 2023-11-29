class Solution {
    void bfs(int n, vector<int>adj[] , int st, vector<bool>& visited) {
        queue<int> q;
        q.push(st);
        visited[st] = true;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            for(auto i: adj[front]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n+1]; 
        int e = edges.size();
        for(int i = 0; i < e; i++){
            int f = edges[i][0];
            int s = edges[i][1];
            adj[f].push_back(s);
            adj[s].push_back(f);
        }
        vector<bool> visited(n, false);
        bfs(n, adj, source, visited);  
        return visited[source] && visited[destination];
    }
};
