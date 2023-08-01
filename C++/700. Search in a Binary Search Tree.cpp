// Time complexity O(N) , Space Complexity O(N)

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
      
        if(!root) return NULL;   // base case 
        if(root->val==val) return root;
      
        TreeNode* left=searchBST(root->left,val);
        TreeNode* right=searchBST(root->right,val);
      
        return left==NULL?right:left; // if left is null then return right , else return right
        return NULL;       // if rquired node is not present then return null 
    }
};
