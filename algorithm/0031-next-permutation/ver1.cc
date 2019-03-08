static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  void nextPermutation(std::vector<int>& nums) {
    std::next_permutation(nums.begin(), nums.end());
  }
};

