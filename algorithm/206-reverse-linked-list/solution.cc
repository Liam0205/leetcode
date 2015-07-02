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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* pt_listnode_prev = NULL;
        ListNode* pt_listnode_curr = head;
        ListNode* pt_listnode_next;
        while (pt_listnode_curr != NULL) {
            pt_listnode_next = pt_listnode_curr->next;
            pt_listnode_curr->next = pt_listnode_prev;
            pt_listnode_prev = pt_listnode_curr;
            pt_listnode_curr = pt_listnode_next;
        }
        return pt_listnode_prev;
    }
};
