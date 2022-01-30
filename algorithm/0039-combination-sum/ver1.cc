static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

struct Solution {
  using citer_t = typename std::vector<int>::const_iterator;
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    if (candidates.empty() || target < *candidates.begin()) {
      return {};
    }
    std::vector<std::vector<int>> res;
    res.reserve(150);
    std::vector<int> cur;
    back_track(candidates.begin(), candidates.end(), target, &cur, &res);
    return res;
  }

 private:
  void back_track(citer_t first, citer_t last, int target, std::vector<int>* cur,
                  std::vector<std::vector<int>>* res) {
    if (0 == target) {
      res->push_back(*cur);
    }
    for (citer_t iter = first; iter != last && *iter <= target; ++iter) {
      int foo = *iter;
      cur->push_back(foo);
      back_track(iter, last, target - foo, cur, res);
      cur->pop_back();
    }
  }
};
