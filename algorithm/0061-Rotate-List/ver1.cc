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
  ListNode* rotateRight(ListNode* head, int k) {
    const int sz = length(head);
    if (sz < 2) {
      return head;
    }
    k = k % sz;
    if (k == 0) {
      return head;
    }
    std::shared_ptr<ListNode> sentry = std::make_shared<ListNode>(0, head);
    ListNode* fast = sentry.get();
    ListNode* slow = sentry.get();
    for (int i = 0; i != k; ++i) {
      fast = fast->next;
    }

    while (nullptr != fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    ListNode* prev = slow;
    slow = prev->next;

    sentry->next = slow;
    fast->next = head;
    prev->next = nullptr;
    return sentry->next;
  }

 private:
  int length(ListNode* head) {
    int cnt = 0;
    while (nullptr != head) {
      ++cnt;
      head = head->next;
    }
    return cnt;
  }
};
