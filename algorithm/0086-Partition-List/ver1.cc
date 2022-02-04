static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

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
  ListNode* partition(ListNode* head, int x) {
    if (nullptr == head) {
      return nullptr;
    }
    std::shared_ptr<ListNode> less = std::make_shared<ListNode>();
    std::shared_ptr<ListNode> greater_equal = std::make_shared<ListNode>();
    ListNode* l = less.get();
    ListNode* ge = greater_equal.get();
    while (nullptr != head) {
      ListNode* tmp = head;
      head = head->next;
      tmp->next = nullptr;
      if (tmp->val < x) {
        l->next = tmp;
        l = l->next;
      } else {
        ge->next = tmp;
        ge = ge->next;
      }
    }
    l->next = greater_equal->next;
    return less->next;
  }
};
