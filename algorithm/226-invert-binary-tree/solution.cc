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
    TreeNode* invertTree(TreeNode* root) {
        if (!root || !(root -> left || root -> right)) {
            return root;
        } else {
            TreeNode* temp = root -> left;
            root -> left   = root -> right;
            root -> right  = temp;
            root -> left   = invertTree(root -> left);
            root -> right  = invertTree(root -> right);
        }
        return root;
    }
};
