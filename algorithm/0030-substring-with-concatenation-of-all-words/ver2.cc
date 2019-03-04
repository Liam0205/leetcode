static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<int> findSubstring(std::string& s, std::vector<std::string>& words) {
    if (s.empty() or words.empty()) {
      return {};
    } else /* lbi */;
    std::vector<int> res;
    std::unordered_map<std::string, uint64_t> counts;
    std::for_each(words.begin(), words.end(), [&counts](const std::string& w){ ++counts[w]; });
    const size_t ssize = s.size(), num = words.size(), wsize = words[0].size();
    for (size_t offset = 0; offset != wsize; ++offset) {
      for (size_t i = offset; i < ssize - num * wsize + 1; i += wsize) {
        size_t j;
        std::unordered_map<std::string, std::vector<size_t>> seen;
        size_t jump = 0;
        for (j = 0; j != num; ++j) {
          const std::string& word = s.substr(i + j * wsize, wsize);
          if (counts.find(word) != counts.end()) {
            seen[word].emplace_back(i + j * wsize);
            if (seen[word].size() > counts[word]) {
              jump = seen[word][0];
              break;
            } else /* lbi */;
          } else {
            jump = i + wsize * j;
            break;
          }
        }
        if (j == num) {
          res.emplace_back(i);
        } else {
          i = jump;
        }
      }
    }
    return res;
  }
};

