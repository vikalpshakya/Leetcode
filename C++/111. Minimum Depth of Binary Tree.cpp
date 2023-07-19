//  Time complexity = O(n)   Space complexity = O(H) 

class Solution {
public:
    int minDepth(TreeNode* root) {

        if ( root == NULL) return 0;

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
      
        if(root->left == NULL || root->right == NULL)    // if the binary root  has only one child node, then the maximum depth and minimum depth would be same 
            return 1+max(leftDepth,rightDepth);  
        else
          return 1+ min(leftDepth , rightDepth) ;

    }
};
