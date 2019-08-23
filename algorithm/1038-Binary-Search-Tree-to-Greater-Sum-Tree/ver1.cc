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
    inversed_midorder_traverse(root, op);
    return root;
  }

 private:
  template <typename UnaryOp>
  void inversed_midorder_traverse(TreeNode* node, UnaryOp op) {
    std::stack<TreeNode*> buffer;
    while (nullptr != node or not buffer.empty()) {
      while (nullptr != node) {
        buffer.push(node);
        node = node->right;                 // loop to the final right node
      }
      node = buffer.top();
      buffer.pop();
      op(node->val);                        // output the final right node in this moment
      node = node->left;                    // look at its left child, if any
    }
  }
};

