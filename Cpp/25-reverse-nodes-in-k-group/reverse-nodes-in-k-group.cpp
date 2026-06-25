/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    int len(ListNode* head) {
        int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (len(head) < k)
            return head;

        // reverse the list from head to head + k

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        int count = 0;

        while (curr && count != k) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        ListNode* nextK = reverseKGroup(next, k);
        head-> next = nextK;

        return prev;
    }
};

