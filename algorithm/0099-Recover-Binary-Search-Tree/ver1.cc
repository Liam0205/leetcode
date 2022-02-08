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
  void recoverTree(TreeNode* root) {
    if (nullptr == root) {
      return;
    }
    TreeNode* left_max = getMaxNode(root->left);
    TreeNode* right_min = getMinNode(root->right);
    bool left_unbalance = nullptr != left_max && left_max->val > root->val;
    bool right_unbalance = nullptr != right_min && right_min->val < root->val;
    std::cout << left_unbalance << ' ' << right_unbalance << '\n';
    if (left_unbalance && right_unbalance) {
      std::swap(left_max->val, right_min->val);
    } else if (left_unbalance) {
      std::swap(left_max->val, root->val);
    } else if (right_unbalance) {
      std::swap(right_min->val, root->val);
    } else {
      recoverTree(root->left);
      recoverTree(root->right);
    }
  }

 private:
  TreeNode* getMinNode(TreeNode* root) const {
    if (nullptr == root) {
      return nullptr;
    }
    TreeNode* cmp = getMinNode(root->left);
    TreeNode* res = root;
    if (nullptr != cmp && res->val > cmp->val) {
      res = cmp;
    }
    cmp = getMinNode(root->right);
    if (nullptr != cmp && res->val > cmp->val) {
      res = cmp;
    }
    return res;
  }

  TreeNode* getMaxNode(TreeNode* root) const {
    if (nullptr == root) {
      return nullptr;
    }
    TreeNode* cmp = getMaxNode(root->left);
    TreeNode* res = root;
    if (nullptr != cmp && res->val < cmp->val) {
      res = cmp;
    }
    cmp = getMaxNode(root->right);
    if (nullptr != cmp && res->val < cmp->val) {
      res = cmp;
    }
    return res;
  }
};
