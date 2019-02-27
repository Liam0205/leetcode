class Solution {
public:
  inline
  bool isMatch(const std::string& s, const std::string& p) {
    if (p.empty()) {
      return s.empty();
    } else /* lbi */;
    size_t ssize = s.size();
    size_t psize = p.size();
    /* dp[i][j] = s[0, i) maches p[0, j); */
    std::vector<std::vector<bool>> dp(ssize + 1, std::vector<bool>(psize + 1, false));
    dp[0][0] = true;  // empty s matches empty p.
    for (size_t j = 1; j <= psize; ++j) {
      dp[0][j] = (j > 1 and p[j - 1] == '*' and dp[0][j - 2]);
    }
    for (size_t i = 1; i <= ssize; ++i) {
      for (size_t j = 1; j <= psize; ++j) {
        if ('*' == p[j - 1]) {
          const char x = p[j - 2];
          dp[i][j] = (dp[i][j - 2] or dp[i - 1][j] and ('.' == x or s[i - 1] == x));
        } else {
          const char x = p[j - 1];
          dp[i][j] = (dp[i - 1][j - 1] and ('.' == x or s[i - 1] == x));
        }
      }
    }
    return dp[ssize][psize];
  }
};

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

