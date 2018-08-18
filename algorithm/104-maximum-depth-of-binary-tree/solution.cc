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
    int maxDepth (TreeNode *root) {
        // the max depth of a tree is
        // the max depth of the sub-trees of the root node plus 1
        // hence, recursion is the answer!
        return root ? (max(maxDepth(root -> left), maxDepth(root -> right)) + 1) : 0;
    }
};
