// ----Recursive approach---------
// Time complexity O(n^2) , space complexity O(n)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* newhead = reverseList(head->next);
        ListNode* temp = newhead;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = head ;
        temp->next->next=NULL;

        return newhead;
    }
};
