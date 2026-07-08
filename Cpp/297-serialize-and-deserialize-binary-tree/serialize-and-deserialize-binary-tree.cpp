/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    vector<string> data;
    string serialize(TreeNode* root) {
        string ans = "";
        if (!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode* front = q.front();
                q.pop();
                if (front)
                    ans = ans + to_string(front->val) + ",";
                else {
                    ans += "#,";
                    continue;
                }

                if (front->left)
                    q.push(front->left);
                else
                    q.push(nullptr);

                if (front->right)
                    q.push(front->right);
                else
                    q.push(nullptr);
            }
        }
        // cout << ans;
        return ans;
    }

    TreeNode* deserialize(string str) {
        string curr = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != ',')
                curr += str[i];
            else {
                if(!curr.empty())
                    data.push_back(curr);
                curr = "";
            }
        }
        if (data.empty())
            return nullptr;

        if (!curr.empty())
            data.push_back(curr);

        int n = data.size();
        // cout << n << endl;

        int val = stoi(data[0]);
        TreeNode* head = new TreeNode(val);
        queue<TreeNode*> q;
        q.push(head);

        // cout << endl << head->val << endl;

        for (int i = 0; !q.empty() && i < n; i++) {
            TreeNode* front = q.front();
            q.pop();

            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;

            if (leftChild < n) {
                if (data[leftChild] != "#") {
                    int num = stoi(data[leftChild]);
                    TreeNode* left = new TreeNode(num);
                    if(front)
                        front->left = left;
                    q.push(left);
                }
            }
            if (rightChild < n) {
                if (data[rightChild] != "#") {
                    int num = stoi(data[rightChild]);
                    TreeNode* right = new TreeNode(num);
                    if(front)
                        front->right = right;
                    q.push(right);
                }
            }
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));