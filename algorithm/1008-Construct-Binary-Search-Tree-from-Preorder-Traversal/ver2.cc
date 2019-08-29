static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* bstFromPreorder(const std::vector<int>& preorder) {
    TreeNode* dummy = new TreeNode(std::numeric_limits<int>::max());
    std::stack<TreeNode*> s;
    s.push(dummy);
    for (int x : preorder) {
      TreeNode* node = new TreeNode(x);
      TreeNode* wk = nullptr;  // find last node whose val is smaller than x
      for (; s.top()->val < x; wk = s.top(), s.pop()) { ; }
      if (wk == nullptr) {
        s.top()->left = node;
      } else {
        wk->right = node;
      }
      s.push(node);
    }
    TreeNode* res = dummy->left;
    dummy->left = nullptr;
    delete dummy;
    return res;
  }
};

