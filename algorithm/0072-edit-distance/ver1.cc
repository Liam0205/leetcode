static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int minDistance(const std::string& word1, const std::string& word2) {
    const int m = word1.size(), n = word2.size();
    if (m > n) {
      return minDistance(word2, word1);
    } else if (m == 0) {
      return n;
    }
    // dp[i][j] represents the edit-distance from `word1[0 ... i)` to `word2[0 ... j)`
    std::vector<std::vector<int>> dp(m + 1, std::vector(n + 1, 0));
    for (int i = 0; i != m + 1; ++i) {
      dp[i][0] = i;
    }
    for (int j = 0; j != n + 1; ++j) {
      dp[0][j] = j;
    }
    for (int i = 1; i != m + 1; ++i) {
      int ii = i - 1;
      for (int j = 1; j != n + 1; ++j) {
        int jj = j - 1;
        if (word1[ii] == word2[jj]) {
          dp[i][j] = dp[ii][jj];
        } else {
          dp[i][j] = std::min({dp[ii][jj], dp[ii][j], dp[i][jj]}) + 1;
        }
      }
    }
    return dp[m][n];
  }
};
