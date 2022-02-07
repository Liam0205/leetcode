static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int numTrees(const int n) {
    if (n == 0) {
      return 0;
    } else if (n == 1) {
      return 1;
    }
    std::vector<int> num{1, 1};
    num.resize(n + 1, 0);
    for (int i = 2; i != n + 1; ++i) {
      for (int j = 0; j != i; ++j) /* j: size of left child tree */ {
        int left_sz = j, right_sz = i - 1 - j;
        num[i] += num[left_sz] * num[right_sz];
      }
    }
    return num[n];
  }
};
