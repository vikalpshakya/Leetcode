class Solution {
public:
/*-------NAIVE APPROACH ------// 
  TIME COMPLEXITY O(n^2)
  SPACE COMPLEXITY O(n)  */

    int height(TreeNode*root){
        if(root==nullptr) return 0;
        return 1+max(height(root->left) , height(root->right));
    }
    int diameterOfBinaryTree_naive(TreeNode* root) {
        if(root == nullptr) return 0;
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 =height(root->left)+height(root->right);
        return max(option3,max(option1,option2));
    }

// -------------OPTIMIZED APPROACH -------------  // 
// Time complexity O(N)   space complexity O(n) 

pair<int,int> diameterOfBinaryTree_pair(TreeNode* root) {
    if(root==nullptr) {
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
        }
      pair<int,int>leftAns = diameterOfBinaryTree_pair(root->left);
      pair<int,int>rightAns = diameterOfBinaryTree_pair(root->right);
      int ld = leftAns.second;
      int lh = leftAns.first;
      int rd = rightAns.second;
      int rh = rightAns.first;
      int height = 1+max(lh,rh);
      int diameter = max(lh+rh,max(ld,rd));
      pair<int,int>p;
      p.first = height;
      p.second = diameter ;
      return p;
    }
int diameterOfBinaryTree(TreeNode* root){
    return diameterOfBinaryTree_pair(root).second;}
};
