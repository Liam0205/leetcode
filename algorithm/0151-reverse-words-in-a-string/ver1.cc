#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::string reverseWords(std::string& s) {
    trim(s);
    trim_consective(s);
    std::reverse(s.begin(), s.end());
    size_t sz = s.size(), b, e;
    for (b = 0; (e = s.find(' ', b)) != std::string::npos; b = e + 1) {
      std::reverse(s.begin() + b, s.begin() + e);
    }
    std::reverse(s.begin() + b, s.end());
    return s;
  }

 private:
  void trim(std::string& s) {
    s.erase(0, s.find_first_not_of(trim_chars));
    s.erase(s.find_last_not_of(trim_chars) + 1);
  }

  void trim_consective(std::string& s) {
    s.erase(std::unique(s.begin(), s.end(), [](auto l, auto r) { return l == r and l == ' '; }),
            s.end());
  }

  const char* trim_chars = " \t\n\r\v\f";
};

