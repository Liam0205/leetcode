static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int uniquePathsWithObstacles(const std::vector<std::vector<int>>& obstacleGrid) {
    const size_t m = obstacleGrid.size();
    const size_t n = obstacleGrid[0].size();
    std::vector<std::vector<size_t>> dp(m + 1, std::vector<size_t>(n + 1, 0));
    // dp[1][1] must be `1`.
    // init dp[0][1] or dp[1][0] to 1 to ensure that.
    dp[0][1] = 1;
    for (size_t i = 1; i != m + 1; ++i) {
      for (size_t j = 1; j != n + 1; ++j) {
        if (obstacleGrid[i - 1][j - 1] == 0) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }
    return dp[m][n];
  }
};
