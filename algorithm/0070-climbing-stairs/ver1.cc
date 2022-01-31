static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int climbStairs(int n) {
    if (n < 1)
      return 0;
    else if (n == 1)
      return 1;
    else if (n == 2)
      return 2;
    std::vector<int> vec_int_fibonacci(n, 1);
    vec_int_fibonacci[1] = 2;
    for (size_t i = 2; i != n; ++i) {
      vec_int_fibonacci[i] = vec_int_fibonacci[i - 1] + vec_int_fibonacci[i - 2];
    }
    return vec_int_fibonacci.back();
  }
};
