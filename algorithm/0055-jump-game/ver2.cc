static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  bool canJump(const std::vector<int>& nums) {
    const size_t sz = nums.size();
    size_t furthest = 0;
    for (size_t i = 0; i != sz; ++i) {
      if (furthest < i) {
        return false;
      }
      furthest = std::max(furthest, i + nums[i]);
    }
    return true;
  }
};
