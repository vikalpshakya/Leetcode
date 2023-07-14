// You are given the head of a linked list and an integer k.
// Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).


 /***Time complexity - O(n) , space complexity O(1) ***/
class Solution {
public: 
  // The code will run perfectly even without finding the length of the link list   //

    int lenght(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        return count ;
    }
// -------------main function --------------//
    ListNode* swapNodes(ListNode* head, int k) {
        if(lenght(head)-1 %k ==0) return head; // if len-1%k==0 , that means both starting and ending kth element are same , so we can just return head directly 
        ListNode* slow = head , *fast = head ; 
        while (--k){
            fast=fast->next;
        }
        ListNode* first = fast ; // placing the  the first pointer 
        while ( fast->next != NULL){ // finding the second pointer named slow 
            slow = slow->next ;
            fast=fast->next ; 
        }
        swap( first->val , slow->val );
        return head;
        }
    };

