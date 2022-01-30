static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
      return {};
    }
    const size_t m = matrix.size();
    const size_t n = matrix[0].size();
    int mode = 0, round = 0;
    size_t i = 0, j = 0;
    std::vector<int> res;
    res.reserve(m * n);
    while (res.size() < m * n) {
      round = mode / 4;
      switch (mode % 4) {
        case 0:
          for (; j != n - round; ++j) {
            res.push_back(matrix[i][j]);
          }
          --j, ++i;
          break;
        case 1:
          for (; i != m - round; ++i) {
            res.push_back(matrix[i][j]);
          }
          --i, --j;
          break;
        case 2:
          for (; j != -1 + round; --j) {
            res.push_back(matrix[i][j]);
          }
          ++j, --i;
          break;
        case 3:
          for (; i != 0 + round; --i) {
            res.push_back(matrix[i][j]);
          }
          ++i, ++j;
          break;
        default:
          break;
      }
      ++mode;
    }
    return res;
  }
};
