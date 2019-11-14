static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int repeatedNTimes(std::vector<int>& A) {
    std::unordered_set<int> s;
    for (int x : A) {
      if (s.find(x) != s.end()) {
        return x;
      } else {
        s.insert(x);
      }
    }
    return 0;
  }
};

