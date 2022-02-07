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
  std::vector<TreeNode*> generateTrees(int n) {
    if (0 == n) {
      return {};
    } else if (1 == n) {
      return {new TreeNode(1)};
    }
    return genBST(0, n);
  }

 private:
  // Devide & conquer.
  std::vector<TreeNode*> genBST(const int first, const int last) const {
    if (!(first < last)) {
      return {nullptr};
    }
    using trees_t = std::vector<TreeNode*>;
    trees_t res;
    // NOTE(Liam): the in-order traversal result of a BST is first + 1, first + 2, ..., last.
    for (int i = first; i != last; ++i) {
      trees_t left_trees, right_trees;  // possible left child trees & right child trees.
      int ii = i + 1;                   // node number
      left_trees = genBST(first, i);
      right_trees = genBST(i + 1, last);
      for (auto left_tree : left_trees) {
        for (auto right_tree : right_trees) {
          // get all possible combinations of left chhild trees & right child trees.
          res.emplace_back(new TreeNode(ii));
          res.back()->left = left_tree;
          res.back()->right = right_tree;
        }
      }
    }
    return res;
  }
};
