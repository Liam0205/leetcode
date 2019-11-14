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
    for (size_t b = 0, e = 0; b != sz and e != std::string::npos; b = e + 1) {
      e = s.find_first_of(' ', b);
      if (e == std::string::npos) {
        std::reverse(s.begin() + b, s.end());
      } else {
        std::reverse(s.begin() + b, s.begin() + e);
      }
    }
    return s;
  }
};

