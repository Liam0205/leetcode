class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        do {
            res.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));
        return res;
    }
};
