static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    const int m = matrix.size(), n = matrix[0].size();
    if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) {
      return false;
    }
    int first = 0, last = m * n;  // last: after tail pointer.
    while (first < last) {
      int mid = first + (last - first) / 2;
      int cmp = matrix[mid / n][mid % n];
      if (cmp < target) {
        first = mid + 1;
      } else if (cmp > target) {
        last = mid;
      } else {
        return true;
      }
    }
    return false;
  }
};
