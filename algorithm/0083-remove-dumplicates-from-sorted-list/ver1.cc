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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
      return head;
    }
    ListNode* wk = head;
    while (wk->next) {
      if (wk->val == wk->next->val)
        deleteOneNode(wk, wk->next);
      else
        wk = wk->next;
    }
    return head;
  }

 private:
  void deleteOneNode(ListNode* prev, ListNode* curr) {
    prev->next = curr->next;
    delete curr;
  }
};
