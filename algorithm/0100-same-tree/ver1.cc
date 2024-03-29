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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
      return true;
    } else if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) {
      return false;
    } else {
      return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
  }
};
