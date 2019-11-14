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
      std::string  mask(52, '\0');
      for (size_t i = 0; i < sz; i += 2) ++mask[s[i] - 'a'];
      for (size_t i = 1; i < sz; i += 2) ++mask[s[i] - 'a' + 26];
      recorder.insert(mask);
    }
    return recorder.size();
  }
};

