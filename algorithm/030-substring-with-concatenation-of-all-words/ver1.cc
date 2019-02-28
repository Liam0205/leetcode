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
    const size_t ssize = s.size(), words_size = words.size(), wsize = words[0].size();
    for (size_t i = 0; i != ssize - words_size * wsize + 1; ++i) {
      std::unordered_map<std::string, uint64_t> seen;
      size_t j;
      for (j = 0; j != words_size; ++j) {
        const std::string& word = s.substr(i + j * wsize, wsize);
        if (counts.find(word) != counts.end()) {
          ++seen[word];
          if (seen[word] > counts[word]) {
            break;
          } else /* lbi */;
        } else {
          break;
        }
      }
      if (j == words_size) {
        res.emplace_back(i);
      } else /* lbi */;
    }
    return res;
  }
};

// Runtime:      224 ms, faster than 49.17%
// Memory Usage: 21.1 MB, less than 63.49%

