static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  int strStr(const std::string& haystack, const std::string& needle) {
    size_t res = haystack.find(needle);
    res = res == std::string::npos ? -1 : res;
    return res;
  }
};

