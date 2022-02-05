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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (nullptr == head || (left == right)) {
      return head;
    }
    std::shared_ptr<ListNode> sentry = std::make_shared<ListNode>(0, head);
    ListNode *lprev = sentry.get(), *l = sentry->next;
    for (int i = 1; i != left; ++i) {
      lprev = l;
      l = l->next;
    }
    ListNode* r = l;
    for (int i = 0; i != right - left; ++i) {
      r = r->next;
    }

    ListNode* prev = r->next;
    ListNode* term = prev;
    while (l != term) {
      ListNode* next = l->next;
      l->next = prev;
      prev = l;
      l = next;
    }
    lprev->next = r;
    return sentry->next;
  }
};
