//    Time complexity: O(N)
//    Space complexity: O(N)

/*     APPROACH :
       I noticed that level order traversal is nothing but just the reverse of alternate levels of a binary tree.
       So we first found the level order traversal of the input tree and stored it in a vector<vector>result.
       And then we reversed sub-vectors of the result (original big vector) alternatively 
       (first reversed the sub-vector at the 1st index then at 3rd index then at 5th index and so on).  */

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) { 
        //Traversing the tree level wise 
        vector<vector<int>>ans;
        if(root==nullptr) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> vec;
            while(size--){
                TreeNode* newHead = q.front();
                q.pop();
                vec.push_back(newHead->val);
                if(newHead->left) q.push(newHead->left);
                if(newHead->right) q.push(newHead->right);
            }
            ans.push_back(vec);
        }
        return ans;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result =  levelOrderBottom(root);
    //  Reversing sub vectors which we got from level order traversal
        for (int i = 1; i < result.size(); i += 2) {
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
};

