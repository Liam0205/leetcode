static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int numDecodings(const std::string& s) {
    const int sz = s.size();
    if (sz == 0 || s[0] == '0') {
      return 0;
    }

    int one = 1, two = 1;
    for (int i = 1; i != sz; ++i) {
      if (s[i] == '0') /* encounter '0': have to combine with a previous '1' or '2'. */ {
        if (s[i - 1] != '1' && s[i - 1] != '2') {
          return 0;
        } else {
          int res = two;
          two = one;
          one = res;
        }
      } else if ('1' <= s[i] && s[i] <= '6') /* able to combine with a previous '1' or '2'. */ {
        if (s[i - 1] != '1' && s[i - 1] != '2') {
          int res = one;
          two = one;
          one = res;
        } else {
          int res = two + one;
          two = one;
          one = res;
        }
      } else /* '7' <= s[i] && s[i] <= '9'; able to combine with a previous '1'. */ {
        if (s[i - 1] != '1') {
          int res = one;
          two = one;
          one = res;
        } else {
          int res = two + one;
          two = one;
          one = res;
        }
      }
    }
    return one;
  }
};
