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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        if (root -> left) {
            vector<int> temp = inorderTraversal(root -> left);
            result.reserve(result.size() + temp.size());
            result.insert(result.end(), temp.begin(), temp.end());
        }
        result.push_back(root -> val);
        if (root -> right) {
            vector<int> temp = inorderTraversal(root -> right);
            result.reserve(result.size() + temp.size());
            result.insert(result.end(), temp.begin(), temp.end());
        }
        return result;
    }
};
