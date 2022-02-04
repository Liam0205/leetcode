static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int maximalRectangle(std::vector<std::vector<char>>& matrix) {
    const int m = matrix.size(), n = matrix[0].size();
    if (0 == m || 0 == n) {
      return 0;
    }
    if (1 == m && 1 == n) {
      return matrix[0][0] - '0';
    }
    std::vector<std::vector<int>> mat(m, std::vector<int>(n, 0));
    for (int i = 0; i != m; ++i) {
      for (int j = 0; j != n; ++j) {
        if (matrix[i][j] == '1') {
          mat[i][j] = 1;
          for (int ii = 0; ii != i && matrix[i - ii - 1][j] == '1'; ++ii) {
            mat[i][j] += 1;
          }
        }
      }
    }
    int res = 0;
    for (int i = 0; i != m; ++i) {
      res = std::max(res, largestRectangleArea(mat[i]));
    }
    return res;
  }

 private:
  int largestRectangleArea(const std::vector<int>& heights) {
    const size_t sz = heights.size();
    if (0 == sz) {
      return 0;
    } else if (1 == sz) {
      return heights[0];
    }
    std::vector<int> span_to_left(sz, -1);
    std::vector<int> span_to_right(sz, sz);

    for (size_t i = 1; i != sz; ++i) {
      int p = 0;
      for (p = i - 1; p >= 0 && heights[p] >= heights[i]; p = span_to_left[p]) {
      }
      span_to_left[i] = p;

      size_t ii = sz - 1 - i;
      for (p = ii + 1; p < sz && heights[p] >= heights[ii]; p = span_to_right[p]) {
      }
      span_to_right[ii] = p;
    }

    int res = 0;
    for (size_t i = 0; i != sz; ++i) {
      res = std::max(res, heights[i] * (span_to_right[i] - span_to_left[i] - 1));
    }
    return res;
  }
};
