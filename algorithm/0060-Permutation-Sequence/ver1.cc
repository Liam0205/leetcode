static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::string getPermutation(int n, int k) {
    std::string res;
    std::generate_n(std::back_inserter(res), n, [i = 1]() mutable { return '0' + i++; });
    if (k == 1) {
      return res;
    }
    for (int i = 0; i != k - 1; ++i) {
      std::next_permutation(res.begin(), res.end());
    }
    return res;
  }
};
