#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 private:
  using map_t = std::map<char, int>;

 public:
  int countPalindromicSubsequences(const std::string& s) {
    const int modbase = 1000000007, sz = s.size();
    int res = 0;

    // * dp[L][b][c] records:
    //     how many unique palindrome subsequences, starting with `c`,
    //     are contained in `s.substr(b, L)`.
    // * sum of (dp[sz][0][c]) is the result.
    // * when update `dp`, for `len < L - 2` are useless, thus `dp.size() == 3`.
    map_t* dp[3];
    for (auto& v : dp) {
      v = new map_t[sz];
    }

    for (int l = 0; l < sz; ++l, std::swap(dp[2], dp[1]), std::swap(dp[1], dp[0])) {
      for (int b = 0; b + l < sz; ++b) {
        for (const char c : "abcd") {
          if (l == 0) {
            dp[0][b][c] = static_cast<int>(s[b] == c);
          } else if (s[b]     != c) {
            dp[0][b][c] = dp[1][b + 1][c];  // since l >= 1; we have: b + 1 <= b + l < n.
          } else if (s[b + l] != c) {
            dp[0][b][c] = dp[1][b][c];
          } else {
            dp[0][b][c] = 2;
            for (const char cc : "abcd") {
              dp[0][b][c] += dp[2][b + 1][cc];
              dp[0][b][c] %= modbase;
            }
          }
        }
      }
    }

    for (const char c : "abcd") {
      res += dp[1][0][c];  // just swapped by `std::swap(dp[1], dp[0])`
      res %= modbase;
    }

    for (auto& v : dp) {
      delete[] v;
    }
    return res;
  }
};

