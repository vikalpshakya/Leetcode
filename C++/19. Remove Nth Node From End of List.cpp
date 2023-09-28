// Time complexity: O(n), Space complexity: O(1)
class Solution {
    int len(ListNode*head){
        int l = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            l++;
        }
        return l;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        int length = len(head);
        if(length == n) return head->next;
        int pos = length - n - 1;
        ListNode* temp = head;
        while(temp && pos --){
            temp = temp->next;
        }
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete(del);
        return head;
    }
};
