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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x = 0, y = 0, carry = 0, digit_sum = 0;
        ListNode *result = NULL, **workingNode = &result;
        
        while (l1 != NULL || l2 != NULL) {
            x = getValue(l1); y = getValue(l2);
            moveNext(l1);     moveNext(l2);
            digit_sum      = carry + x + y;
            ListNode* node = new ListNode(digit_sum % 10);
            *workingNode   = node;
            workingNode    = &(node->next);
            carry          = digit_sum / 10;
        }
        
        if (carry > 0) {
            ListNode* node = new ListNode(carry % 10);
            *workingNode   = node;
        }
        
        return result;
    }
private:
    int getValue (const ListNode* &node) {
        int value = 0;
        if (node != NULL) {
            value = node->val;
        }
        return value;
    }
    void moveNext (ListNode* &node) {
        if (node != NULL) {
            node = node->next;
        }
    }
};
