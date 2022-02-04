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
  ListNode* deleteDuplicates(ListNode* head) {
    std::shared_ptr<ListNode> sentry = std::make_shared<ListNode>(std::numeric_limits<int>::min(), head);

    ListNode *valid = sentry.get(), *prev = valid, *test = sentry->next;
    while (nullptr != test) {
      if (prev->val != test->val) {
        if (prev->next == test) {
          valid = prev;
          prev = test;
        } else {
          ListNode* to_delete = valid->next;
          while (to_delete != test) {
            ListNode* tmp = to_delete;
            to_delete = to_delete->next;
            // delete tmp;
          }
          valid->next = test;
          prev = test;
        }
      }
      test = test->next;
    }

    if (nullptr != prev->next) {
      while (nullptr != valid->next) {
        ListNode* tmp = valid->next;
        valid->next = tmp->next;
        // delete tmp;
      }
    }

    return sentry->next;
  }
};
