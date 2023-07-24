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
    int maximum(TreeNode* root){
        if(root==nullptr) return INT_MIN;
        return max({root->val,maximum(root->left),maximum(root->right)});
    }
    int minimum(TreeNode* root){
        if(root==nullptr) return INT_MAX;
        return min({root->val, minimum(root->left) , minimum(root->right)}); 
    }
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        // below is counter case
        if((root->left and root->val <= maximum(root->left)) or (root->right and root->val >= minimum(root->right)))
            return false;
        
        return isValidBST(root->left) and isValidBST(root->right);
    }
};
