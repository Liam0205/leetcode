class Solution {
 public:
  int maxArea(const std::vector<int>& height) {
    int res = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i < j) {
      int h = std::min(height[i], height[j]);
      res   = std::max(res, h * (j - i));
      while (i < j and height[i] <= h) { ++i; }
      while (i < j and height[j] <= h) { --j; }
    }
    return res;
  }
};

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

