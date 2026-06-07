class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> mappa;
        set<int> children;

        for (vector<int>& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];

            children.insert(child);
            TreeNode *parentNode, *childNode;
            
            if (mappa.find(parent) != mappa.end())
                parentNode = mappa[parent];
            else {
                parentNode = new TreeNode(parent);
                mappa[parent] = parentNode;
            }

            if (mappa.find(child) != mappa.end())
                childNode = mappa[child];
            else {
                childNode = new TreeNode(child);
                mappa[child] = childNode;
            }

            if (isLeft)
                parentNode->left = childNode;
            else
                parentNode->right = childNode;
        }

        for (auto [parent, node] : mappa) {
            if (children.find(parent) == children.end())
                return node;
        }
        return new TreeNode(-1);
    }
};