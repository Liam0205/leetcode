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
  TreeNode* insertIntoBST(TreeNode* const root, const int val) {
    TreeNode* newnode = new TreeNode(val);
    if (nullptr == root) {
      return newnode;
    } else {
      TreeNode* prev = root;
      TreeNode* node = root;
      while (nullptr != node) {
        prev = node;
        if (val < node->val) {
          node = node->left;
        } else if (val > node->val) {
          node = node->right;
        } else {
          std::terminate();
        }
      }
      if (val < prev->val) {
        prev->left = newnode;
      } else if (val > prev->val) {
        prev->right = newnode;
      } else {
        std::terminate();
      }
      return root;
    }
  }
};

