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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode* pt_listnode_wk = head;
        while (pt_listnode_wk->next) {
            if (pt_listnode_wk->val == pt_listnode_wk->next->val)
                deleteOneNode (pt_listnode_wk, pt_listnode_wk->next);
            else
                pt_listnode_wk = pt_listnode_wk->next;
        }
        return head;
    }
private:
    void deleteOneNode (ListNode* prev, ListNode* curr) {
        prev->next = curr->next;
        delete curr;
    }
};
