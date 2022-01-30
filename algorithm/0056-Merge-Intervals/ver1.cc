static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int>& l, const std::vector<int>& r) -> bool {
                return l[0] < r[0] || (l[0] == r[0] && l[1] > r[1]);
              });
    // return intervals;
    std::vector<std::vector<int>> res;
    res.reserve(intervals.size());
    std::vector<int> candidate(intervals[0]);
    for (const auto& inter : intervals) {
      if (inter[0] <= candidate[1]) {
        if (inter[1] >= candidate[1]) {
          candidate[1] = inter[1];
        } else {
          /* do nothing */
        }
      } else {
        res.push_back(candidate);
        candidate = inter;
      }
    }
    res.push_back(candidate);
    return res;
  }
};
