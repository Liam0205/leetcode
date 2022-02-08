static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  bool isInterleave(const std::string& s1, const std::string& s2, const std::string& s3) {
    const int s1sz = s1.size(), s2sz = s2.size(), s3sz = s3.size();
    if (s1sz + s2sz != s3sz) {
      return false;
    }
    std::vector<std::vector<bool>> dp(s1sz + 1, std::vector<bool>(s2sz + 1, false));
    dp[0][0] = true;
    for (int i = 1; i != s2sz + 1; ++i) {
      dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
    }
    for (int i = 1; i != s1sz + 1; ++i) {
      dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
    }
    for (int i = 1; i != s1sz + 1; ++i) {
      for (int j = 1; j != s2sz + 1; ++j) {
        dp[i][j] =
            (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
      }
    }

    return dp[s1sz][s2sz];
  }
};
