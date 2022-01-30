static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int lengthOfLastWord(const std::string& s) {
    size_t right = s.find_last_not_of(' ');
    if (right == std::string::npos) {
      right = s.size();
    } else {
      ++right;
    }
    size_t left = s.find_last_of(' ', right - 1);
    if (left == std::string::npos) {
      left = 0;
    } else {
      ++left;
    }
    return right - left;
  }
};
