class Solution {
public:

 // Time complexity: O(N) , Space complexity: O(1)

    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next ){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
};
