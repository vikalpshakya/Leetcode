/*  Time complexity: O(N)
    Space complexity: O(H)  */

class Solution {
public:
    TreeNode* sortedListToBST_helper(vector<int>&ans,int start , int end){
        if(start > end) return NULL;
        int mid = (start+end)/2;
        TreeNode* newHead= new TreeNode(ans[mid]);
        TreeNode* left = sortedListToBST_helper(ans,start,mid-1);
        TreeNode*right = sortedListToBST_helper(ans,mid+1,end);
        newHead->left = left;
        newHead->right = right;
        return newHead;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>ans;
        ListNode*temp = head;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        int start = 0 , end = ans.size()-1;
        return sortedListToBST_helper(ans,start,end);
    }
};
