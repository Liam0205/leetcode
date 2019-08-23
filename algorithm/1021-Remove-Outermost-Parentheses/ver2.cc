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
    int unpaired = 0;
    for (const char c : S) {
      if (c == ')') { --unpaired; }
      if (unpaired > 0) { res += c; }
      if (c == '(') { ++unpaired; }
    }
    return res;
  }
};

