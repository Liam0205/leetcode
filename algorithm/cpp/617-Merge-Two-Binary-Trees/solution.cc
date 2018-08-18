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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (nullptr == t1 and nullptr == t2) {
            return nullptr;
        } else {
            TreeNode* root = new TreeNode((nullptr != t1 ? t1->val : 0) + (nullptr != t2 ? t2->val : 0));
            root->left  = mergeTrees((nullptr != t1 ? t1->left : nullptr),  (nullptr != t2 ? t2->left : nullptr));
            root->right = mergeTrees((nullptr != t1 ? t1->right : nullptr), (nullptr != t2 ? t2->right : nullptr));
            return root;
        }
    }
};
