static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
   std::string toLowerCase(std::string& s) {
      std::transform(s.begin(), s.end(), s.begin(), [](auto c){ return std::tolower(c); });
      return s;
  }
};

