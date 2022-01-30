static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int jump(std::vector<int>& nums) {
    const size_t sz = nums.size();
    if (sz < 2) {
      return 0;
    } else if (sz < 3) {
      return 1;
    }
    int res = 0;
    std::vector<int> jump(sz, 0);
    for (size_t i = 0; i != sz - 1; ++i) {
      size_t ii = sz - 2 - i;
      if (sz - 1 - ii <= nums[ii]) {
        jump[ii] = 1;
      } else {
        int min = std::numeric_limits<int>::max() - 1;
        for (size_t j = 0; j != nums[ii]; ++j) {
          min = std::min(min, jump[ii + j + 1]);
        }
        jump[ii] = min + 1;
      }
    }
    return jump[0];
  }
};
