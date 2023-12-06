class Solution {
// Time complexity: O(n), Space complexity: O(n) [Recusrive stack space only]
private:
    ListNode* rec(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* first = head;
        ListNode* second = head->next;

        first->next = rec(second->next);
        second->next = first;
        return second;
    }

public:
    ListNode* swapPairs(ListNode* head) {
        return rec(head);
    }
};
