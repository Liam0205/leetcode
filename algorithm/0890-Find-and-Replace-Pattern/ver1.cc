static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words,
                                                        const std::string& pattern) {
    const size_t sz = pattern.size();
    const std::vector<uint8_t> pmask = get_mask(pattern);
    std::vector<std::string> res;
    res.reserve(50);
    for (const auto& word : words) {
      if (word.size() == sz and get_mask(word) == pmask) {
        res.push_back(word);
      }
    }
    return res;
  }

 private:
  std::vector<uint8_t> get_mask(const std::string& word) {
    uint8_t i = 0;
    std::map<char, uint8_t> m;
    std::vector<uint8_t> v;
    v.reserve(word.size());
    for (char c : word) {
      if (m.find(c) == m.end()) {
        m.insert({c, i++});
      }
      v.push_back(m[c]);
    }
    return v;
  }
};

