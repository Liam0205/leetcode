static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> res, res1;

    if (k == n || k == 0) {
      std::vector<std::vector<int>> res2;
      std::vector<int> curr;
      for (int i = 1; i <= k; i++) curr.push_back(i);
      res2.push_back(curr);
      return res2;
    }

    res = combine(n - 1, k - 1);

    for (auto itr = res.begin(); itr != res.end(); itr++) {
      itr->push_back(n);
    }

    res1 = combine(n - 1, k);

    res.insert(res.end(), res1.begin(), res1.end());
    return res;
  }
};
