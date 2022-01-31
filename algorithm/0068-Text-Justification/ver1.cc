static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<std::string> fullJustify(const std::vector<std::string>& words, int maxWidth) {
    std::vector<std::string> res;

    const int sz = words.size();
    for (int first = 0, cnt = 0, word_wd = 0; first < sz; first += cnt) {
      for (cnt = 0, word_wd = 0; first + cnt < sz && word_wd + words[first + cnt].size() + cnt <= maxWidth;
           word_wd += words[first + cnt].size(), ++cnt) {
      }
      std::string line(words[first]);
      for (int i = 0; i < cnt - 1; ++i) {
        if (first + cnt >= sz) {  // last line.
          line.append(" ");
        } else {
          int to_pad = maxWidth - word_wd;
          int base_space = to_pad / (cnt - 1);
          int extra_cnt = to_pad % (cnt - 1);
          int act_space = base_space + (i < extra_cnt ? 1 : 0);
          line.append(act_space, ' ');
        }
        line.append(words[first + i + 1]);
      }
      line.append(maxWidth - line.size(), ' ');
      res.push_back(line);
    }
    return res;
  }
};
