// -----------Approach 1 -----------//

//-------- Time complexity: O(n), Space complexity : O(n) ---------// 

class Solution {
    void preOrder(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        ans.push_back(root->val);

        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
    void flattenTree(TreeNode* root){
        vector<int> ans;
        preOrder(root, ans);

        if (ans.empty()) return;

        TreeNode* current = root;

        for (int i = 1; i < ans.size(); i++) {
            current->left = nullptr;
            current->right = new TreeNode(ans[i]);
            current = current->right;
        }
    }
// ------------- APPROACH 2 ----------- //

// ------Time complxity : O(n), Space complexity: O(h) --- // 

    TreeNode* prev = NULL;
    void dfs(TreeNode* root){

        if(root == NULL) return;

        dfs(root->right);
        dfs(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }


public:
    void flatten(TreeNode* root) {
        // flattenTree(root);
        dfs(root);
    }
};


