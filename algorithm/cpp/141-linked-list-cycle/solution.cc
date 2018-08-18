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
        /* EXPLANATION:
        *  If a linked list has a cycle, there must be a node which
        *  two different nodes point to. Taking an example:
        *    head -> ... -> a -> b -> ... -> c -> b -> ...
        *  Let's think about the way we reverse a linked list. The first time
        *  that we encounter b, we make it pointing back to a, and move to
        *  the next node (into the cycle). Now, we've processed c and move to
        *  b again, and b is pointing to a. That is, after we process b twice,
        *  we'll process every node before b, in the original list, and
        *  eventually back to head.
        *  Hence, if a linked list has a cycle, and if we reverse it, we'll
        *  have two same head.
        */
        return (head == NULL || head -> next == NULL) ?
            false : head == reverseSinglyLinkedList(head);
    }
private:
    ListNode* reverseSinglyLinkedList (ListNode *head) {
        if (head == NULL) return head;
        ListNode *prev = NULL, *curr = NULL, *nxt = NULL;
        curr = head;
        nxt  = curr -> next;
        while (nxt) {
            curr -> next = prev;
            prev = curr;
            curr = nxt;
            nxt  = curr -> next;
        }
        return curr;
    }
};
