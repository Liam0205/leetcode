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
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    ListNode sentry(42);
    ListNode* work = &sentry;
    while (std::any_of(lists.begin(), lists.end(), [](ListNode* p){ return p != nullptr; })) {
      auto mit = std::min_element(lists.begin(), lists.end(), [](ListNode* lhs, ListNode* rhs){
            if (lhs == nullptr) {
              return false;
            } else if (rhs == nullptr) {
              return true;
            } else {
              return lhs->val < rhs->val;
            }
          });
      work->next = (*mit);
      work = work->next;
      *mit = work->next;
    }
    return sentry.next;
  }
};

