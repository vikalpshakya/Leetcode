class Solution {
public:
    /*
        there are k bits . . . .
        total possible arrangements of 0 , 1 in k bits -> (2 ^ k)

        single there are equal number of ways to achieve even & odd sum

        so number of ways to to achieve odd sum =  (2 ^ k) / 2
                                                => 2 ^ (k-1)
    */
    const int sz = 1e5 + 1;
    const int mod = 1e9 + 7;

    int binPow(int e, int x) {
        if (x == 0) return 1;

        long long res = binPow(e, x / 2);
        res = (res % mod * res % mod) % mod;

        if (x & 1)
            res = (res % mod * e % mod) % mod;

        return res % mod;
    }

    int k = 0;

    int dfs(int src, vector<int> adj[]) {

        int depth = 0;

        for (auto it : adj[src]) {
            depth = max(depth, 1 + dfs(it, adj));
        }

        k = max(k, depth);
        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[sz];

        for (auto it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
        }

        dfs(1, adj);

        cout << k << endl;

        // now we have to calculate 2 ^ k - 1 % 1e9

        int ans = binPow(2, k - 1);

        return ans;
    }
};
