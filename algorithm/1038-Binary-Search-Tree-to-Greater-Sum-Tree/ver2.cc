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
  TreeNode* bstToGst(TreeNode* root) {
    int sum = 0;
    auto op = [&sum](int& val) {
      sum += val;
      val  = sum;
    };
    inversed_midorder_traverse_recursively(root, op);
    return root;
  }

 private:
  template <typename UnaryOp>
  void inversed_midorder_traverse_recursively(TreeNode* node, UnaryOp& op) {
    if (nullptr != node) {
      if (nullptr != node->right) { inversed_midorder_traverse_recursively(node->right, op); }
      op(node->val);
      if (nullptr != node->left) { inversed_midorder_traverse_recursively(node->left, op); }
    }
  }
};

