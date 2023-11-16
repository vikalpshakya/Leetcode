// Time comlpexity O(N) , sapce complexity O(N)  // 

class Solution {
public:
    TreeNode* sortedArrayToBST_helper(vector<int>& nums , int start , int end){
        if(start>end) return NULL;
        int mid = (start+end) / 2;
        TreeNode* newRoot = new TreeNode(nums[mid]); 
        newRoot->left = sortedArrayToBST_helper(nums,start,mid-1);
        newRoot->right = sortedArrayToBST_helper(nums,mid+1,end);
        return newRoot;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0 , end = nums.size()-1;
        return sortedArrayToBST_helper(nums,start,end);
    }
};
