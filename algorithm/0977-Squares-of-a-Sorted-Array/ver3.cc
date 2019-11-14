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
    const size_t sz = A.size();
    if (sz < 2) { return A; }
    std::vector<int> res(sz);
    auto l = A.begin();
    auto r = A.rbegin();
    for (auto i = res.rbegin(); i != res.rend(); ++i) {
      if (*l > *r) {
        *i = *(l++);
      } else {
        *i = *(r++);
      }
    }
    return res;
  }
};

