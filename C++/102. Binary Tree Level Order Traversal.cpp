//     Time complexity O(N) space O(N)    //

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr) return ans;
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
};
