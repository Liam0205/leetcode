/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

static int x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(0);
    return 0;
}();

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* lastp;

        // typical merge sort like process
        while (nullptr != p1 and nullptr != p2) {
            int tmp = p1->val + p2->val + carry;
            p2->val = p1->val =  tmp % 10;
            carry = tmp / 10;
            lastp = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        int longer = 1;
        // here NULL == p1 OR NULL ==p2       
        while (nullptr != p1) {
            int tmp = p1->val + carry;
            p1->val = tmp % 10;
            carry = tmp / 10;
            lastp = p1;
            p1 = p1->next;
        }
        
        while (nullptr != p2) {
            longer = 2;
            int tmp = p2->val + carry;
            p2->val = tmp % 10;
            carry = tmp / 10;
            lastp = p2;
            p2 = p2->next;
        }
        
        if (0 != carry) {
            lastp->next = new ListNode(carry);
        }
        
        return (1 == longer) ? l1 : l2;   // output longer list
    }
};
