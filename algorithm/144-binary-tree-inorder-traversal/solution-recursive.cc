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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        else result.push_back(root -> val);
        if (root -> left) {
            vector<int> temp = preorderTraversal(root -> left);
            result.reserve(result.size() + temp.size());
            result.insert(result.end(), temp.begin(), temp.end());
        }
        if (root -> right) {
            vector<int> temp = preorderTraversal(root -> right);
            result.reserve(result.size() + temp.size());
            result.insert(result.end(), temp.begin(), temp.end());
        }
        return result;
    }
};
