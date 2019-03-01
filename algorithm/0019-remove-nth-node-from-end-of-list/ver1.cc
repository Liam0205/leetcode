static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* const head, const int n) {
    ListNode sentry(42);
    sentry.next = head;
    ListNode *prev = &sentry, *slow = head, *fast = head;
    for (size_t i = 0; i != n; ++i, fast = fast->next) {
      if (fast == nullptr) {
        return sentry.next;
      } else /* lbi */;
    }
    while (fast != nullptr) {
      fast = fast->next;
      prev = slow;
      slow = slow->next;
    }
    if (slow != nullptr) {
      prev->next = slow->next;
      delete slow;
    } else /* lbi */;
    return sentry.next;
  }
};

