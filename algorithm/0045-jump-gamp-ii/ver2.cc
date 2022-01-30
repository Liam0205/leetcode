static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int jump(const std::vector<int>& nums) {
    const int sz = nums.size();
    int curr_pos = 0, furthest = 0, least_jump = 0;
    for (int i = 0; i != sz - 1; ++i) {
      // greedy: always try to jump to the furthest position,
      //         considering that finaly we will jump to the end.
      furthest = std::max(furthest, i + nums[i]);
      if (curr_pos == i) {  // still need to jump at least once.
        curr_pos = furthest;
        ++least_jump;
        if (furthest >= sz) {
          return least_jump;
        }
      }
    }
    return least_jump;
  }
};
