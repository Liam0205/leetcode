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
    if (sz == 1) {
      return true;
    }
    size_t furthest = 0, curr_pos = 0;
    for (size_t i = 0; i != sz - 1; ++i) {
      furthest = std::max(furthest, i + nums[i]);
      if (curr_pos == i) {  // still need to jump at least once.
        curr_pos = furthest;
        if (furthest >= sz - 1) {
          return true;
        }
      }
    }
    return false;
  }
};
