static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    const size_t sz = matrix.size();
    // diag mirror.
    for (size_t i = 0; i != sz; ++i) {
      for (size_t j = 0; j != i; ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
    // left-right mirror
    for (size_t i = 0; i != sz; ++i) {
      for (size_t j = 0; j != sz / 2; ++j) {
        std::swap(matrix[i][j], matrix[i][sz - 1 - j]);
      }
    }
  }
};
