class Solution {
public:
//   Time complexity = O(n*log(n)) , Space complexity O(n)  

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } 
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    ListNode* findMidPoint(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
//    Main function  
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* mid = findMidPoint(head);
        ListNode* midNext = mid->next;
        mid->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(midNext);
        return mergeTwoLists(left, right);
    }
};
