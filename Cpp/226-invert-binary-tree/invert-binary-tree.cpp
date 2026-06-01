/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
 
class Solution {
public:
    void solve(TreeNode* root) {
        if (!root) return;
        
        if (root->left && root->right)
            swap(root->left, root->right);
        else if (root->left) {
            TreeNode* newRight = root->left;
            root->right = newRight;
            root->left = nullptr;
        } 
        else if (root->right) {
            TreeNode* newLeft = root->right;
            root->left = newLeft;
            root->right = nullptr;
        }
        solve(root->left);
        solve(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};