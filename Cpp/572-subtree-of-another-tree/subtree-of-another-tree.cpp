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
    bool isThere = false;

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    void rec(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return;
        if (root->val == subRoot->val) {
            isThere |= isSameTree(root, subRoot);
        }
        rec(root->left, subRoot);
        rec(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

         rec(root, subRoot);
         return isThere;
    }
};