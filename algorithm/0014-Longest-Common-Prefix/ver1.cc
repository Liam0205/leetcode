class Solution {
 public:
  std::string longestCommonPrefix(const vector<string>& strs) {
    if (strs.empty()) {
      return std::string("");
    } else if (1 == strs.size()) {
      return strs[0];
    } else /* lbi */;
    return std::reduce(strs.begin() + 1, strs.end(), strs[0],
        [](const std::string& a, const std::string& b) {
          return std::string(a.begin(), std::mismatch(a.begin(), a.end(), b.begin()).first);
        });
  }
};

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

