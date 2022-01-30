static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::string addBinary(const std::string& a, const std::string& b) {
    if (a.size() > b.size()) {
      return addBinary(b, a);
    }
    int carry = 0;
    std::string res;
    for (int i = 0; i != b.size(); ++i) {
      int ii = a.size() - 1 - i;
      int jj = b.size() - 1 - i;
      int tmp = ii < 0 ? (b[jj] - '0') + carry : (a[ii] - '0') + (b[jj] - '0') + carry;
      if (tmp == 0 || tmp == 2) {
        res.push_back('0');
      } else {
        res.push_back('1');
      }
      carry = tmp > 1 ? 1 : 0;
    }
    if (carry > 0) {
      res.push_back('1');
    }
    return std::string(res.rbegin(), res.rend());
  }
};
