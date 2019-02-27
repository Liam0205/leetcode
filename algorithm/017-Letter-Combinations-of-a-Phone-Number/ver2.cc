static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
 public:
  std::vector<std::string> letterCombinations(const std::string& digits) {
    if (digits.empty()) {
      return {};
    } else /* lbi */;
    std::vector<std::string> res{""};
    size_t reserve_size = 1;
    std::for_each(digits.begin(), digits.end(), [&](char c){ reserve_size *= map[c - '2'].size(); });
    res.reserve(reserve_size);
    for (const char c : digits) {
      const auto& vec  = map[c - '2'];
      const size_t rsz = res.size();
      const size_t vsz = vec.size();
      for (size_t i = 0; i != vsz - 1; ++i) {
        std::copy(res.begin(), res.begin() + rsz, std::back_inserter(res));
      }
      for (size_t i = 0; i != vsz; ++i) {
        const auto begin = res.begin() + i * rsz;
        const auto end   = res.begin() + (i + 1) * rsz;
        const auto& c    = vec[i];
        for (auto iter = begin; iter != end; ++iter) {
          *iter += c;
        }
      }
    }
    return res;
  }
  static std::vector<std::string> map;
};

std::vector<std::string> Solution::map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

