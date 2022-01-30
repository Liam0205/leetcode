static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(cosnt std::vector<std::string>& strs) {
    std::unordered_map<std::string, size_t> dedup;
    std::vector<std::vector<std::string>> res;
    for (const std::string& str : strs) {
      std::string s(str);
      std::sort(s.begin(), s.end());
      auto search = dedup.find(s);
      if (search == dedup.end()) {
        dedup.emplace(s, res.size());
        res.emplace_back({str});
      } else {
        res[search->second].emplace_back(str);
      }
    }
    return res;
  }
};
