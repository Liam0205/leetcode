static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> res;
    std::vector<int> comb(k, 0);
    for (int i = 0; i >= 0;) {
      ++comb[i];
      if (comb[i] > n - k + i + 1) {
        --i;
      } else if (i == k - 1) {
        res.push_back(comb);
      } else {
        ++i;
        comb[i] = comb[i - 1];
      }
    }
    return res;
  }
};
