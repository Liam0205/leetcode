static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals,
                                       const std::vector<int>& newInterval) {
    intervals.push_back(newInterval);
    return merge(intervals);
  }

 private:
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> res;
    res.reserve(intervals.size());
    const size_t sz = intervals.size();
    int l = intervals[0][0], r = intervals[0][1];
    for (size_t i = 1; i != sz; ++i) {
      const auto& inter = intervals[i];
      if (inter[0] <= r) {
        if (inter[1] > r) {
          r = inter[1];
        } else {
          /* do nothing */
        }
      } else {
        res.push_back({l, r});
        l = inter[0];
        r = inter[1];
      }
    }
    res.push_back({l, r});
    return res;
  }
};
