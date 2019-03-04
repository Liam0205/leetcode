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
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          if (i == 1) {
            record[i] = 2;
          } else {
            record[i] = 2 + record[i - 2];
          }
        } else {
          int pos = i - record[i - 1] - 1;
          if (pos == 0 and s[pos] == '(') {
            record[i] = 2 + record[i - 1];
          } else if (pos > 0 and s[pos] == '(') {
            record[i] = 2 + record[i - 1] + record[pos - 1];
          } else /* lbi */;
        }
        res = std::max(res, record[i]);
      } else /* lbi */;
    }
    return res;
  }
};
