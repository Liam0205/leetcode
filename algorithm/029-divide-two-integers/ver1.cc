static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  static int32_t divide(const int32_t dividend, const int32_t divisor) {
    if (divisor == 0) {
      throw "Divided by zero!";
    } else if (divisor == 1) {
      return dividend;
    } else if (dividend == divisor) {
      return 1;
    } else if (divisor == std::numeric_limits<int32_t>::min()) {
      return 0;
    } else if (dividend == std::numeric_limits<int32_t>::min()) {
      if (divisor == -1) {
        return std::numeric_limits<int32_t>::max();
      } else {
        return (divisor & 1 == 1) ?
          divide(dividend + 1, divisor) : divide(dividend >> 1, divisor >> 1);
      }
    }
    uint32_t dvd = std::abs(dividend), dvs = std::abs(divisor);
    return dividend < 0 == divisor < 0 ? do_divide(dvd, dvs) : -do_divide(dvd, dvs);
  }

  static int32_t do_divide(uint32_t dvd, uint32_t dvs) {
    int32_t res = 0;
    while (dvd >= dvs) {
      uint32_t bsrch = dvs;
      uint32_t q     = 1;
      while (dvd >= bsrch << 1) {
        bsrch <<= 1;
        q     <<= 1;
      }
      dvd -= bsrch;
      res += q;
    }
    return res;
  }
};

