static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int longestValidParentheses(const std::string& s) {
    const int ssize = s.size();
    if (ssize < 2) {
      return 0;
    } else /* lbi */;
    int record[ssize] = {0};
    int res = 0;
    for (int i = 1; i != ssize; ++i) {
      if (s[i] == ')' and
          i - record[i - 1] - 1 >= 0 and s[i - record[i - 1] - 1] == '(') {
        record[i] = 2 + record[i - 1] +
            (i - record[i - 1] - 1 > 0 ? record[i - record[i - 1] - 2] : 0);
        res = std::max(res, record[i]);
      } else /* lbi */;
    }
    return res;
  }
};
