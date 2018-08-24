/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* odd_head  = nullptr;
        ListNode* even_head = nullptr;
        ListNode* odd_last  = nullptr;
        ListNode* even_last = nullptr;
        ListNode* working   = head;
        bool is_odd         = true;

        while (working != nullptr) {
            if (is_odd) {
                if (odd_head == nullptr) {
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
                if (even_head == nullptr) {
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
        even_last->next = nullptr;
        return odd_head;
    }
};
