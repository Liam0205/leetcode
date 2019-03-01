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
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) {
      return head;
    } else /* lbi */;
    ListNode sentry(42);
    sentry.next = head;
    ListNode *prev = &sentry, *slow = head, *fast = head->next;
    while (fast != nullptr) {
      prev->next = fast;
      slow->next = fast->next;
      fast->next = slow;
      std::swap(slow, fast);
      prev = fast;
      slow = fast->next;
      if (slow != nullptr) {
        fast = slow->next;
      } else {
        break;
      }
    }
    return sentry.next;
  }
};

