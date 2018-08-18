/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* odd_head  = NULL;
        ListNode* even_head = NULL;
        ListNode* odd_last  = NULL;
        ListNode* even_last = NULL;
        ListNode* working   = head;
        bool is_odd         = true;

        while (working != NULL) {
            if (is_odd) {
                if (odd_head == NULL) {
                    odd_head = working;
                    odd_last = odd_head;
                    working  = working->next;
                } else {
                    odd_last->next = working;
                    odd_last = working;
                    working  = working->next;
                }
                is_odd = false;
            } else {
                if (even_head == NULL) {
                    even_head = working;
                    even_last = even_head;
                    working   = working->next;
                } else {
                    even_last->next = working;
                    even_last = working;
                    working   = working->next;
                }
                is_odd = true;
            }
        }

        odd_last->next  = even_head;
        even_last->next = NULL;
        return odd_head;
    }
};
