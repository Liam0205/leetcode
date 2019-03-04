static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    return std::distance(nums.begin(), std::unique(nums.begin(), nums.end()));
  }
};

