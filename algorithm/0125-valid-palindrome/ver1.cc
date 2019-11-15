#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  bool isPalindrome(std::string& s) {
    if (filter_alphanumeric(tolower(s)).empty()) {
      return true;
    } else {
      const size_t half = s.size() / 2;
      auto l = s.begin();
      auto r = s.rbegin();
      for (size_t i = 0; i != half and *l == *r; ++i, ++l, ++r);
      return *l == *r;
    }
  }

 private:
  inline std::string& tolower(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(), [](auto& c) { return std::tolower(c); });
    return s;
  }

  inline std::string& filter_alphanumeric(std::string& s) {
    s.erase(std::remove_if(s.begin(), s.end(), [](auto c) {
          return not(('0' <= c and c <= '9') or ('a' <= c and c <= 'z'));
        }),
        s.end());
    return s;
  }
};

