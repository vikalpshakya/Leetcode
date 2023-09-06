class Solution {
    public:
// Time complexity : O(N) [O(logN) in avg case ,  Space complexity O(1)

        TreeNode* insertIntoBST(TreeNode* root, int val) {
            if( !root ) return new TreeNode(val);
            else if(root->val > val) {
                root->left = insertIntoBST(root->left , val);
            }
            else if(root->val < val){
                root->right = insertIntoBST(root->right , val);
            }
            return root;
        }
};
