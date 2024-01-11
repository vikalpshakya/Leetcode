// o(n^2)

class Solution {
public:
int maxDiff = INT_MIN;

    void findDiff(TreeNode*root, TreeNode* child) {
        
        if(root == NULL || child == NULL ) return;

        maxDiff = max(maxDiff,abs(root->val - child->val));

        findDiff(root,child->left);
        findDiff(root,child->right);

    }

    void minAllNodes(TreeNode* root) {

        if(!root) return ;
    
        findDiff(root,root->left);
        findDiff(root,root->right);
        minAllNodes(root->left);
        minAllNodes(root->right);

    }

    int maxAncestorDiff(TreeNode* root) {
        
        minAllNodes(root);
        return maxDiff;
    
    }
};
