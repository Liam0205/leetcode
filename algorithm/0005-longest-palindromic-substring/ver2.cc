#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::string longestPalindrome(const std::string& s) {
    const int32_t sz = s.size();
    if (sz <= 1) {
      return s;
    } else {
      int32_t max_i = 0, max_l = 1, c = 0;
      while (c < sz) {
        int32_t begin = c, end = c;

        // move center
        for (; end + 1 < sz and s[end] == s[end + 1]; ++end) ;
        c = end + 1;

        for (; begin - 1 >= 0 and end + 1 < sz and s[begin - 1] == s[end + 1]; --begin, ++end) ;

        int32_t cur_l = end + 1 - begin;
        if (cur_l > max_l) {
          max_l = cur_l;
          max_i = begin;
        }
      }
      return s.substr(max_i, max_l);
    }
  }
};

