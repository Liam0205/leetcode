static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<std::vector<int>> generateMatrix(const int n) {
    std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
    const int m = n;
    int mode = 0, round = 0;
    size_t i = 0, j = 0;
    int cnt = 0;
    while (cnt < n * n) {
      round = mode / 4;
      switch (mode % 4) {
        case 0:
          for (; j != n - round; ++j) {
            res[i][j] = ++cnt;
          }
          --j, ++i;
          break;
        case 1:
          for (; i != m - round; ++i) {
            res[i][j] = ++cnt;
          }
          --i, --j;
          break;
        case 2:
          for (; j != -1 + round; --j) {
            res[i][j] = ++cnt;
          }
          ++j, --i;
          break;
        case 3:
          for (; i != 0 + round; --i) {
            res[i][j] = ++cnt;
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
