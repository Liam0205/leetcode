/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> buffer;
        int cnt = 0;
        while (nullptr != root or not buffer.empty()) {
            while (nullptr != root) {
                buffer.push(root);
                root = root->left;
            }
            root = buffer.top();
            buffer.pop();
            ++cnt;
            if (k == cnt) {
                return root->val;
            }
            root = root->right;
        }
    }
};

