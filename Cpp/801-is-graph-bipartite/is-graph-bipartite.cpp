class Solution {
public:
    bool is_bipartite;

    void dfs(int node, int color, vector<vector<int>>& graph, vector<int>& col) {
        col[node] = color;
        for (auto it : graph[node]) {
            if (col[it] == col[node]) {
                is_bipartite = false;
                return;
            }
            if (col[it] == 0) {
                dfs(it, 3 - col[node], graph, col);
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> col(n, 0);
        is_bipartite = true;

        for (int i = 0; i < n; i++) {
            if (col[i] == 0) {
                dfs(i, 1, graph, col);
            }
        }

        return is_bipartite;
    }
};