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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return buildHeightBalancedBST(nums.begin(), nums.end());
    }

private:
    template <typename RandomIt>
    TreeNode* buildHeightBalancedBST(RandomIt first, RandomIt last) {
        if (std::distance(first, last) > 1) {
            RandomIt mid  = first + std::distance(first, last) / 2;
            TreeNode* res = new TreeNode(*mid);
            res->left     = buildHeightBalancedBST(first, mid);
            res->right    = buildHeightBalancedBST(mid + 1, last);
            return res;
        } else if (std::distance(first, last) == 1) {
            return new TreeNode(*first);
        } else {
            return nullptr;
        }
    }
};

