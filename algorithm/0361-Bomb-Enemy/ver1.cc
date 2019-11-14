static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int maxKilledEnemies(const std::vector<std::vector<char>>& grid) {
    if (grid.empty() or grid[0].empty()) return 0;
    size_t m = grid.size(), n = grid[0].size(), cnt_row_enemy, cnt_col_enemy[n];
    int res = 0;
    for (size_t i = 0; i != m; ++i) {
      for (size_t j = 0; j != n; ++j) {
        if (j == 0 or grid[i][j - 1] == 'W') {
          cnt_row_enemy = 0;
          for (size_t k = j; k != n and grid[i][k] != 'W'; ++k) {
            cnt_row_enemy += static_cast<size_t>(grid[i][k] == 'E');
          }
        }
        if (i == 0 or grid[i - 1][j] == 'W') {
          cnt_col_enemy[j] = 0;
          for (size_t k = i; k != m and grid[k][j] != 'W'; ++k) {
            cnt_col_enemy[j] += static_cast<size_t>(grid[k][j] == 'E');
          }
        }
        if (grid[i][j] == '0') {
          res = std::max(static_cast<size_t>(res), cnt_row_enemy + cnt_col_enemy[j]);
        }
      }
    }
    return res;
  }
};

