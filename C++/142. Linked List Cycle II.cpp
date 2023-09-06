class Solution {
public:
// Time complexity: O(N) , Space complexity: O(1)

/*  Floyyd detection algorithm    */

    ListNode *detectCycle(ListNode *head) {
       if(!head) return NULL;
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast && fast->next){
           fast = fast->next->next;
           slow = slow->next;
           if(fast == slow){
                fast = head;
                while(fast!= slow ){
                    fast = fast->next;
                    slow = slow->next;
               }
               return slow;
           }
       }
       return NULL;
    }
};
