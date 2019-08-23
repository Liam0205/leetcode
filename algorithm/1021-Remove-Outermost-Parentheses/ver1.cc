static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::string removeOuterParentheses(const std::string& S) {
    std::string res;
    size_t      offset = 0;
    size_t      lc = 0, rc = 0;
    for (const char c : S) {
      if (c == '(') {
        ++lc;
      } else {
        ++rc;
        if (lc == rc) {
          res += S.substr(offset + 1, 2 * lc - 2);
          offset += 2 * lc;
          lc = 0;
          rc = 0;
        }
      }
    }
    return res;
  }
};

