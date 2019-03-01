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
  ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
    std::vector<ListNode*> nodes;
    for (ListNode* list : lists) {
      while (list != nullptr) {
        nodes.push_back(list);
        list = list->next;
      }
    }
    if (nodes.empty()) {
      return nullptr;
    } else /* lbi */;
    std::sort(nodes.begin(), nodes.end(), [](ListNode* l, ListNode* r) { return l->val < r->val; });
    nodes.back()->next = nullptr;
    for (auto iter = nodes.begin(); iter != nodes.end() - 1; ++iter) {
      (*iter)->next = (*(iter + 1));
    }
    return nodes.front();
  }
};

