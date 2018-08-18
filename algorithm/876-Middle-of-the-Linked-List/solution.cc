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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (nullptr != fast->next and nullptr != fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (nullptr != fast->next) {
            slow = slow->next;
        }
        return slow;
    }
};
