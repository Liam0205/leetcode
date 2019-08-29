static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int repeatedNTimes(std::vector<int>& A) {
    const size_t sz_m2 = A.size() - 2;
    for (size_t i = 0; i != sz_m2; ++i) {
      if (A[i] == A[i + 1] or A[i] == A[i + 2]) { return A[i]; }
    }
    return A.back();
  }
};

