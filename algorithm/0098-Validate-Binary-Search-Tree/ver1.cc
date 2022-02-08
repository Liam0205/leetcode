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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (nullptr == root) {
      return true;
    }
    if ((root->left == nullptr || getMax(root->left) < root->val) &&
        (root->right == nullptr || getMin(root->right) > root->val)) {
      return isValidBST(root->left) && isValidBST(root->right);
    } else {
      return false;
    }
  }

 private:
  int getMin(TreeNode* root) const {
    int res = std::numeric_limits<int>::max();
    while (nullptr != root) {
      res = std::min(res, root->val);
      root = root->left;
    }
    return res;
  }

  int getMax(TreeNode* root) const {
    int res = std::numeric_limits<int>::min();
    while (nullptr != root) {
      res = std::max(res, root->val);
      root = root->right;
    }
    return res;
  }
};
