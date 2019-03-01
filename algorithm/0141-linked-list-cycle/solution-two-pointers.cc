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
    bool hasCycle(ListNode *head) {
        if (!head || !(head -> next)) return false;
        ListNode *fast = head -> next, *slow = head;
        do {
            if (!(fast -> next) || !((fast -> next) -> next)) return false;
            if (slow == fast) return true;
            fast = (fast -> next) -> next;
            slow = slow -> next;
        } while (true);
    }
};
