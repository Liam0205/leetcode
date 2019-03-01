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
 private:
  inline bool update_nodes(ListNode* prev, ListNode* nodes[], const int k) {
    nodes[0] = prev->next;
    for (int i = 1; i != k; ++i) {
      if (nodes[i - 1] != nullptr) {
        nodes[i] = nodes[i - 1]->next;
      } else {
        return false;
      }
    }
    return true;
  }
  inline void reverse_nodes(ListNode* prev, ListNode* nodes[], const int k) {
    prev->next = nodes[k - 1];
    nodes[0]->next = nodes[k - 1]->next;
    for (int i = 1; i != k; ++i) {
      nodes[i]->next = nodes[i - 1];
    }
  }

 public:
  ListNode* reverseKGroup(ListNode* head, const int k) {
    if (head == nullptr or k < 2) {
      return head;
    }
    ListNode sentry(42);
    sentry.next = head;
    ListNode *prev = &sentry;
    ListNode* nodes[k];
    if (not update_nodes(prev, nodes, k)) {
      return sentry.next;
    } else /* lbi */;
    while (nodes[k - 1] != nullptr) {
      reverse_nodes(prev, nodes, k);
      prev = nodes[0];
      if (not update_nodes(prev, nodes, k)) {
        return sentry.next;
      } else /* lbi */;
    }
    return sentry.next;
  }
};

