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
    std::vector<int> comb;
    backtracking(0, n, k, &comb, &res);
    return res;
  }

 private:
  void backtracking(int first, int last, int len, std::vector<int>* comb,
                    std::vector<std::vector<int>>* const res) {
    if (0 == len) {
      res->push_back(*comb);
    } else {
      for (int i = first; i < last; ++i) {
        comb->push_back(i + 1);
        backtracking(i + 1, last, len - 1, comb, res);
        comb->pop_back();
      }
    }
  }
};
