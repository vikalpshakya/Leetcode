// TC O(n^2) , SC O(n)
class Solution {
public:
    int maximum(TreeNode* root){
        int maxi = INT_MIN + 1;
        if(root==nullptr) return maxi;
        return max(root->val,max(maximum(root->left),maximum(root->right)));
    }
    int minimum(TreeNode* root){
        int mini = INT_MAX -1;
        if(root == nullptr) return mini;
        return min(root->val,min(minimum(root->left) , minimum(root->right))); 
    }
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        int leftMax = maximum(root->left);
        int rightMax = minimum(root->right);
        if(root->val>leftMax && root->val<rightMax ){
            if(!isValidBST(root->left) || !isValidBST(root->right)) {
                return false;
            }
            else return true;
        }
        return false;
    }

};


// 1 test case getting failed
// testcase = [-2147483648,null,2147483647] 
