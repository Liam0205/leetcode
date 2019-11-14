#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int numSpecialEquivGroups(std::vector<std::string>& A) {
    std::unordered_set<std::string> recorder;
    for (const std::string& s : A) {
      const size_t sz = s.size();
      std::string odd, even;
      for (size_t i = 1; i < sz; i += 2) {
        even += s[i - 1];
        odd  += s[i];
      }
      if (sz % 2 == 1) {
        even += s[sz - 1];
      }
      std::sort(odd.begin(), odd.end());
      std::sort(even.begin(), even.end());
      recorder.insert(even + ":" + odd);
    }
    return recorder.size();
  }
};

