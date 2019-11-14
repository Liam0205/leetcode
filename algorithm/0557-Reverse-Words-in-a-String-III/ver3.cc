static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::string reverseWords(std::string& s) {
    size_t sz = s.size();
    size_t b, e;
    for (b = 0, e = 0; (e = s.find(' ', b)) != std::string::npos; b = e + 1) {
      std::reverse(s.begin() + b, s.begin() + e);
    }
    std::reverse(s.begin() + b, s.end());
    return s;
  }
};

