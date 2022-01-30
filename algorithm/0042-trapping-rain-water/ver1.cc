static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int trap(std::vector<int>& height) {
    const size_t sz = height.size();
    if (sz < 3) {
      return 0;
    }
    size_t left = 0, right = sz - 1;
    int left_bar = 0, right_bar = 0, total = 0;
    while (left <= right) {
      if (height[left] <= height[right]) {
        if (height[left] < left_bar) {
          total += left_bar - height[left];
        } else {
          left_bar = height[left];
        }
        ++left;
      } else {
        if (height[right] < right_bar) {
          total += right_bar - height[right];
        } else {
          right_bar = height[right];
        }
        --right;
      }
    }
    return total;
  }
};
