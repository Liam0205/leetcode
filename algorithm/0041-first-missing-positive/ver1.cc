static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int firstMissingPositive(std::vector<int>& nums) {
    if (nums.empty()) {
      return 1;
    }
    const int sz = nums.size();
    // the first missing positive in an array with length = sz, must
    //   > 0;
    //   <= sz;
    // or
    // sz + 1.
    for (int i = 0; i != sz; ++i) {
      while (nums[i] > 0 && nums[i] <= sz && nums[i] != nums[nums[i] - 1]) {
        std::swap(nums[i], nums[nums[i] - 1]);
      }
    }
    // for all positive num `a` in [1, sz], it has to have been placed at idx = a - 1.
    for (int i = 0; i != sz; ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return sz + 1;
  }
};
