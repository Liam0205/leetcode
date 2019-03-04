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
  ListNode* mergeTwoLists(ListNode* lhs, ListNode* rhs) {
    if (lhs == nullptr) {
      return rhs;
    } else if (rhs == nullptr) {
      return lhs;
    } else /* lbi */;
    ListNode sentry(42);
    ListNode* work = &sentry;
    while (lhs != nullptr and rhs != nullptr) {
      if (lhs->val < rhs->val) {
        work->next = lhs;
        work = work->next;
        lhs = work->next;
      } else {
        work->next = rhs;
        work = work->next;
        rhs = work->next;
      }
    }
    if (lhs != nullptr) {
      work->next = lhs;
    } else {
      work->next = rhs;
    }
    return sentry.next;
  }
};

