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
    if (m == 0) {
      return n;
    } else if (n == 0) {
      return m;
    }
    // dp[i][j] represents the edit-distance from `word1[0 ... i)` to `word2[0 ... j)`
    int dp[m + 1][n + 1];
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
          dp[i][j] = std::min({dp[ii][jj] /* replace */, dp[ii][j] /* insert */, dp[i][jj] /* delete */}) + 1;
        }
      }
    }
    return dp[m][n];
  }
};
