// Time complexity: O(V+E), Space complexity: O(V)

class Solution {
private:
    bool dfs(int n,vector<vector<int>>& adj,vector<bool>& visited, 
        vector<bool>& inPath,vector<bool>& check, int sv){
        visited[sv] = true;
        inPath[sv] = true;
        check[sv] = false;
        for(auto i : adj[sv]){
            if(!visited[i]){
                if(dfs(n,adj,visited,inPath,check,i)){
                    check[sv] = false;
                    return true;
                }
                
            }
            else if(inPath[i]){
                check[sv] = false;
                return true ;
            }
            
        }
        check[sv] = true;
        inPath[sv] = false;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool>visited(n,false);
        vector<bool>inPath(n,false);
        vector<bool>check(n,false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(n,adj,visited,inPath,check,i);
            }
        }
        vector<int>ans; // to store the safe nodes
        for(int i = 0; i < n; i++){
            if(check[i])
                ans.push_back(i);
        }
        return ans;
    }
};
