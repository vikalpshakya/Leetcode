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
    ListNode* middle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* rev(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* ans = rev(head->next);
        head->next->next = head;
        head->next = NULL;

        return ans;
    }

    int pairSum(ListNode* head) {
        int sum = 0;
        ListNode* temp = head;
        ListNode* mid = middle(temp);
        ListNode* rev_mid = rev(mid);

        while (head && rev_mid) {
            if (sum < head->val + rev_mid->val) {
                sum = head->val + rev_mid->val;
            }
            head = head->next;
            rev_mid = rev_mid->next;
        }
        
        return sum;
    }
};