#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  bool validPalindrome(const std::string& s) {
    if (isPalindrome(s)) {
      return true;
    } else {
      const size_t half = s.size() / 2;
      size_t l = 0, r = s.size();
      for (size_t i = 0; i != half and s[l] == s[r - 1]; ++i, ++l, --r);
      return isPalindrome(s.substr(l, r - l - 1)) or isPalindrome(s.substr(l + 1, r - l - 1));
      if (s[l] == s[r - 2]) {
        return isPalindrome(s.substr(l + 1, r - l - 2));
      } else if (s[l + 1] == s[r - 1]) {
        return isPalindrome(s.substr(l + 2, r - l - 2));
      } else {
        return false;
      }
    }
  }

 private:
  bool isPalindrome(const std::string& s) {
    if (s.empty()) {
      return true;
    } else {
      const size_t half = s.size() / 2;
      auto l = s.begin();
      auto r = s.rbegin();
      for (size_t i = 0; i != half and *l == *r; ++i, ++l, ++r);
      return *l == *r;
    }
  }
};

