static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int balancedStringSplit(const std::string& s) {
    int counter = 0;
    int res = 0;
    for (const auto& c : s) {
      if (c == 'L') {
        ++counter;
      } else {
        --counter;
      }
      if (counter == 0) {
        ++res;
      }
    }
    return res;
  }
};

