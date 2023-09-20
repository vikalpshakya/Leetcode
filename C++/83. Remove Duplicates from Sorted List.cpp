class Solution {
public:
// Time Complexity: O(n), Space Complexity: O(1)

    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* current = head;
        while(current && current->next){
            if(current->val == current->next->val){
                current->next = current->next->next;
            }
            else
                current = current->next;
        }
        return head;
    }
};
