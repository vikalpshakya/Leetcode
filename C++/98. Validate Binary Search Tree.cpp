/*---------NAIVE APPROACH -------
    TIME COMPLEXITY: O(n^H), SPACE COMPLEXITY: O(n)      */
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
/*----------OPTIMIZED APPROACH ----------------
    Time Complexity: O(n) Space complexity O(n)    */
class Solution {
public:
    bool isValidBST_helper(TreeNode* root,long long  min,long long  max ) {
        if(!root) return true;  
        if(root->val <= min || root->val >= max) return false;
        bool isLeftOk = isValidBST_helper(root->left,min,root->val);
        bool isRightOk = isValidBST_helper(root->right,root->val,max);
        return isLeftOk && isRightOk;
    }
    bool isValidBST(TreeNode* root){
        long long min = LLONG_MIN;
        long long  max = LLONG_MAX;
        return isValidBST_helper(root,min,max);
    }
};
