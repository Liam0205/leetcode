static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    do {
      res.emplace_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));
    return res;
  }
};

