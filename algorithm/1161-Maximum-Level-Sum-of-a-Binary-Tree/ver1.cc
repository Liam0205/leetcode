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
  int maxLevelSum(TreeNode* root) {
    int res;
    bfs_traverse_btree(root, &res);
    return res;
  }

 private:
  void bfs_traverse_btree(TreeNode* root, int* res) {
    std::queue<TreeNode*> q;
    q.push(root);
    for (int lv = 1, max = std::numeric_limits<int>::min(); not q.empty(); ++lv) {
      const size_t node_in_cur_lv = q.size();
      int sum = 0;
      for (size_t i = 0; i != node_in_cur_lv; ++i) {
        TreeNode* node = q.front();
        sum += node->val;
        if (node->left != nullptr) { q.push(node->left); }
        if (node->right != nullptr) { q.push(node->right); }
        q.pop();
      }
      if (sum > max) {
        max = sum;
        *res = lv;
      }
    }
  }
};

