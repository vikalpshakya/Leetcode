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
}; // OPTIMIZED 

// Time complexity O(n) , space complexity O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* newhead = reverseList(temp->next);
        temp->next->next = head ; 
        temp->next = NULL;
        return newhead ; 
    }
}
