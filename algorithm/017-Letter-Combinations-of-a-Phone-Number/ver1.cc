static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
 public:
  std::vector<std::string> letterCombinations(const std::string& digits) {
    std::vector<std::vector<std::string>> tmp;
    tmp.reserve(digits.size());
    std::transform(digits.begin(), digits.end(), std::back_inserter(tmp),
        [](char a){ return map[a]; });
    return std::accumulate(tmp.begin(), tmp.end(), std::vector<std::string>(), getCartesianProduct);
  }
  static std::vector<std::string> getCartesianProduct(const std::vector<std::string>& a,
                                               const std::vector<std::string>& b) {
    if (a.empty()) {
      return b;
    } else if (b.empty()) {
      return a;
    } else /* lbi */;
    const size_t asize = a.size(), bsize = b.size();
    std::vector<std::string> res;
    res.reserve(asize * bsize);
    for (const auto& as : a) {
      for (const auto& bs : b) {
        res.emplace_back(as + bs);
      }
    }
    return res;
  }
  static std::map<char, std::vector<std::string>> map;
};

std::map<char, std::vector<std::string>> Solution::map = {
    {'2', {"a", "b", "c"}},
    {'3', {"d", "e", "f"}},
    {'4', {"g", "h", "i"}},
    {'5', {"j", "k", "l"}},
    {'6', {"m", "n", "o"}},
    {'7', {"p", "q", "r", "s"}},
    {'8', {"t", "u", "v"}},
    {'9', {"w", "x", "y", "z"}}
  };

