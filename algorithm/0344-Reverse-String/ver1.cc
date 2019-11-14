static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  void reverseString(std::vector<char>& s) {
    std::reverse(s.begin(), s.end());
  }
};

