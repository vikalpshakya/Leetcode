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

    void print(ListNode* head){
        if(!head) cout << "null\n";
        else cout << head->val << endl;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        int count = 0;

        ListNode* temp = head;

        ListNode* start1 = nullptr;
        ListNode* start2 = nullptr;
        ListNode* end = nullptr;

        while(temp && count <= right) {
            count++;
            if(count < left) start1 = temp;
            if(count == left) start2 = temp;
            if(count == right) end = temp->next;
            temp = temp->next;
        }
        
        // print(start1);
        // print(start2);
        print(end);

        ListNode*curr = start2;
        ListNode* prev = nullptr;
        ListNode*next = nullptr;

        while(curr && curr != end) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        // cout << endl;
        // print(start1);
        // print(start2);
        // print(prev);

        if(start1 )
            start1 ->next = prev;
        else {
            head->next = end;
            return prev;
        }
        start2 ->next = next;

        return head;

    }
};