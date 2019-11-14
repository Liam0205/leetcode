#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::string nearestPalindromic(const std::string& n) {
    const size_t num_digits = n.size();
    const long   num = std::stol(n);

    std::set<long, std::less<long>> cands;
    cands.insert(static_cast<long>(std::pow(10, num_digits)) + 1);
    cands.insert(static_cast<long>(std::pow(10, num_digits - 1)) - 1);
    const long significants = std::stol(n.substr(0, (num_digits + 1) / 2));
    for (int i = 0; i != 3; ++i) {
      std::string left = std::to_string(significants + i - 1);
      std::string right(left.rbegin() + (num_digits & 0x01), left.rend());
      cands.insert(std::stol(left + right));
    }

    long res, diff = std::numeric_limits<long>::max();
    cands.erase(num);
    for (long val : cands) {
      const long temp = std::abs(val - num);
      if (temp < diff) {
        diff = temp;
        res  = val;
      }  // remember that std::set is ordered, hence no need to handle temp == diff.
    }
    return std::to_string(res);
  }
};

