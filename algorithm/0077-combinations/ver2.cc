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
      // here, we still need to add `len` elements into `*comb`, and
      // `i + 1` is the smallest one of those elements.
      // if `i >= last - len + 1`, then there is not enough elements to be
      // added. We could strip the number of times of the loop, and
      // thus reduce times of recursively function calling.
      const int upper = std::min(last, last - len + 1);
      for (int i = first; i < upper; ++i) {
        comb->push_back(i + 1);
        backtracking(i + 1, last, len - 1, comb, res);
        comb->pop_back();
      }
    }
  }
};
