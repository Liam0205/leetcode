static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    auto iter = digits.rbegin();
    for (; iter != digits.rend() && *iter == 9; ++iter) {
      *iter = 0;
    }
    if (iter != digits.rend()) {
      *iter += 1;
    } else {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};
