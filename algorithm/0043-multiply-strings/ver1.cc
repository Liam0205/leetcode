static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::string multiply(const std::string& num1, const std::string& num2) {
    const size_t sz1 = num1.size(), sz2 = num2.size();
    // length of res would be no longer than sz1 + sz2.
    std::string res(sz1 + sz2, '\0');
    for (size_t i = 0; i != sz1; ++i) {
      const size_t ii = sz1 - 1 - i;
      int carry = 0;
      for (size_t j = 0; j != sz2; ++j) {
        const size_t jj = sz2 - 1 - j;
        // multiply by digit.
        int tmp = res[ii + jj + 1] + (num1[ii] - '0') * (num2[jj] - '0') + carry;
        res[ii + jj + 1] = tmp % 10;
        carry = tmp / 10;
      }
      res[ii] += carry;
    }

    const size_t first = res.find_first_not_of('\0');
    if (first == std::string::npos) {
      return "0";
    } else {
      for (size_t i = first; i != sz1 + sz2; ++i) {
        res[i] += '0';
      }
      return res.substr(first);
    }
  }
};
