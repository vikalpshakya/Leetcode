//   Time complexity : O(n) , Space complexity O(n ) 

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root ) {
        vector<vector<int>>ans;
        if(root==nullptr) return ans ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> vec;
            while(size--){
                TreeNode* newHead = q.front();
                q.pop();
                vec.push_back(newHead->val);
                if(newHead->left) q.push(newHead->left);
                if(newHead->right) q.push(newHead->right);
            }
            ans.push_back(vec);
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        vector<vector<int>>result = levelOrderBottom(root);
        
        for(int i = 0 ; i < result.size() ; i++){
            ans.push_back(result[i][result[i].size()-1]);
        }
        return ans;
    }
};
