static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  void sortColors(std::vector<int>& nums) {
    int cnt[3] = {0};
    const int sz = nums.size();
    for (auto n : nums) {
      ++(cnt[n]);
    }
    for (int i = 0, j = 0; i != 3; ++i) {
      for (int k = 0; k != cnt[i]; ++k, ++j) {
        nums[j] = i;
      }
    }
    return;
  }
};
