static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  void setZeroes(std::vector<std::vector<int>>& matrix) {
    const int m = matrix.size(), n = matrix[0].size();
    int64_t bitmap_column[4] = {0};
    for (int i = 0; i != m; ++i) {
      bool clear = false;
      for (int j = 0; j != n; ++j) {
        if (matrix[i][j] == 0) {
          bitmap_column[j / 64] |= 1LL << (j % 64LL);
          clear = true;
        }
      }
      if (clear) {
        std::fill(matrix[i].begin(), matrix[i].end(), 0);
      }
    }
    for (int j = 0; j != n; ++j) {
      if (((1LL << (j % 64LL)) & bitmap_column[j / 64]) != 0) {
        for (int i = 0; i != m; ++i) {
          matrix[i][j] = 0;
        }
      }
    }
    return;
  }
};
