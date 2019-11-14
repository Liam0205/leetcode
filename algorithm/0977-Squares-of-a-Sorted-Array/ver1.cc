static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<int> sortedSquares(std::vector<int>& A) {
    std::transform(A.begin(), A.end(), A.begin(), [](int x) { return x * x; });
    std::sort(A.begin(), A.end());
    return A;
  }
};

