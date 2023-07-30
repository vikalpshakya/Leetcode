// Time complexity: O(n) , Space complexity: O(n)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int>ans;
        inorderTraversal_helper(root,ans);
        return ans;
    }
    void inorderTraversal_helper(TreeNode* root , vector<int>&ans) {
        if(!root) return ;
        inorderTraversal_helper(root->left,ans);
        ans.push_back(root->val);
        inorderTraversal_helper(root->right,ans);
    }
};
