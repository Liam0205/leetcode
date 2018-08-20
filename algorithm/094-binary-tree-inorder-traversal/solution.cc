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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (nullptr == root) {
            return result;
        }
        auto do_traverse = [&result](TreeNode* node) { result.push_back(node->val); };
        midorder_traverse(root, do_traverse);
        return result;
    }

private:
    template <typename UnaryOp>
    void midorder_traverse(TreeNode* node, UnaryOp do_traverse) {
        std::stack<TreeNode*> buffer;
        while (nullptr != node or not buffer.empty()) {
            while (nullptr != node) {
                buffer.push(node);
                node = node->left;
            }
            node = buffer.top();
            buffer.pop();
            do_traverse(node);
            node = node->right;
        }
    }
};

