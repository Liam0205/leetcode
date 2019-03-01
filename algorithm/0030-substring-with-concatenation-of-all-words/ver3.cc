static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<int> findSubstring(const std::string& s, const std::vector<std::string>& words) {
    if (s.empty() or words.empty()) {
      return {};
    }
    std::vector<int> res;
    const size_t ssize = s.size(), num = words.size(), wsize = words[0].size();
    std::unordered_map<std::string, size_t> counts;
    std::for_each(words.begin(), words.end(), [&counts](const std::string& w){ ++counts[w]; });
    for (size_t offset = 0; offset < wsize; offset++) {
      std::unordered_map<std::string, size_t> seen;
      size_t i, j, cnt = 0;
      std::string word;
      for (i = offset, j = offset; i < ssize - num * wsize + 1; j += wsize) {
        word = s.substr(j, wsize);
        if (counts.find(word) != counts.end()) {
          ++seen[word];
          ++cnt;
          if (seen[word] <= counts[word]) {
            if (cnt == num) {
              res.emplace_back(i);
              --seen[s.substr(i, wsize)];
              i += wsize;
              --cnt;
            } else /* lbi */;
          } else {
            while (seen[word] > counts[word]) {
              --seen[s.substr(i, wsize)];
              --cnt;
              i += wsize;
            }
          }
        } else {
          cnt = 0;
          i = j + wsize;
          seen.clear();
        }
      }
    }
    return res;
  }
};

