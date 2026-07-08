/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int maxi = -1e9;

    int help(TreeNode* root) {
        if(!root) return 0;

        int lSum = max(0, help(root->left));
        int rSum = max(0, help(root->right));
        maxi = max(maxi, root->val + lSum + rSum);

        return root->val + max(lSum,rSum);
    }

    int maxPathSum(TreeNode* root) {
        help(root);
        return maxi;
    }
};