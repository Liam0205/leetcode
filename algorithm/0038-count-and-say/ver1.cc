static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

struct Solution {
  std::string countAndSay(const int n) {
    switch (n) {
      case 1:
        return "1";
      case 2:
        return "11";
      case 3:
        return "21";
      case 4:
        return "1211";
      case 5:
        return "111221";
      case 6:
        return "312211";
      case 7:
        return "13112221";
      case 8:
        return "1113213211";
      case 9:
        return "31131211131221";
      case 10:
        return "13211311123113112211";
      case 11:
        return "11131221133112132113212221";
      default: {
        const std::string& foo = countAndSay(n - 1);
        int cnt = 0;
        char cch = '\0';
        std::string res;
        res.reserve(2 * foo.size());
        for (const char ch : foo) {
          if (0 == cnt) {
            cch = ch;
            cnt = 1;
          } else {
            if (cch == ch) {
              ++cnt;
            } else {
              res.append(cnt + '0');
              res.push_back(cch);
              cch = ch;
              cnt = 1;
            }
          }
        }
        res.append(cnt + '0');
        res.push_back(cch);
        return res;
      }
    }
  }
};
