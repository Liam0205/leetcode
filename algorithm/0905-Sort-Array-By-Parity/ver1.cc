static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<int> sortArrayByParity(std::vector<int>& A) {
    size_t i = 0, j = A.size();
    auto swap_true = [&]() { std::swap(A[i], A[j - 1]); return true; };
    do {
      while (i < j and A[i] % 2 == 0) { ++i; }
      while (i < j and A[j - 1] % 2 != 0) { --j; }
    } while (i < j and swap_true());
    return A;
  }
};

