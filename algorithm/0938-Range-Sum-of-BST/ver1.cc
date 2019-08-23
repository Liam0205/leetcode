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
  int rangeSumBST(const TreeNode* const root, const int L, const int R) {
    int sum = 0;
    auto op = [&](int val) {
      sum += (L <= val and val <= R) ? val : 0;
    };
    midorder_traverse_recursively(root, op);
    return sum;
  }

 private:
  template <typename UnaryOp>
  void midorder_traverse_recursively(const TreeNode* const node, UnaryOp& op) {
    if (nullptr != node) {
      if (nullptr != node->left)  { midorder_traverse_recursively(node->left, op); }
      op(node->val);
      if (nullptr != node->right) { midorder_traverse_recursively(node->right, op); }
    }
  }
};

