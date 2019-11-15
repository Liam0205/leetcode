#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int countSubstrings(const std::string& s) {
    int res = 0;
    const size_t sz = s.size();

    for (size_t i = 0; i != sz; ++i) {
      for (size_t j = 0; i >= j     and i + j < sz and s[i - j]     == s[i + j]; ++j) ++res;
      for (size_t j = 0; i >= j + 1 and i + j < sz and s[i - j - 1] == s[i + j]; ++j) ++res;
    }

    return res;
  }
};

