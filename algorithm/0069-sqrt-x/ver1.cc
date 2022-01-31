static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int mySqrt(int x) {
    return x == 0 ? 0 : sqrt_bsrch(x);
  }

 private:
  int sqrt_bsrch(int x) {
    int first = 1, last = x / 2 + 1;
    while (first < last) {
      long mid = (last - first) / 2 + first;
      if (mid * mid <= x) {
        if (mid == first) {
          return first;
        } else {
          first = mid;
        }
      } else {
        last = mid;
      }
    }
    return first;
  }
};
