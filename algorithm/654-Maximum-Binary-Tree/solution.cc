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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = nullptr;
        constructMaximumBinaryTree(nums.begin(), nums.end(), &root);
        return root;
    }

 private:
    bool constructMaximumBinaryTree(std::vector<int>::iterator first, std::vector<int>::iterator last, TreeNode** root) {
        if (std::distance(first, last) < 1) {
            return false;
        } else {
            auto cut = std::max_element(first, last);
            *root = new TreeNode(*cut);
            constructMaximumBinaryTree(first, cut, &((*root)->left));
            constructMaximumBinaryTree(cut + 1, last, &((*root)->right));
            return true;
        }
    }
};
