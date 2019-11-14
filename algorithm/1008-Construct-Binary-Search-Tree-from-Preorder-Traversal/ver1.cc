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
  TreeNode* bstFromPreorder(const std::vector<int>& preorder,
                                          const int bound = std::numeric_limits<int>::max()) {
    if (preorder.size() == i or preorder[i] > bound) { return nullptr; }
    auto node = new TreeNode(preorder[i]);
    ++i;
    node->left = bstFromPreorder(preorder, node->val);
    node->right = bstFromPreorder(preorder, bound);
    return node;
  }

 private:
  size_t i = 0;
};

