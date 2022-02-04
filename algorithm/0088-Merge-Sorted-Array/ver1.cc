static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  void merge(std::vector<int>& nums1, const int m, std::vector<int>& nums2, const int n) {
    if (m == 0) {
      nums1 = nums2;
    }
    size_t i = 0, j = 0, k = 0;
    while (i != m && j != n) {
      size_t ii = m - 1 - i, jj = n - 1 - j, kk = m + n - 1 - k;
      if (nums1[ii] > nums2[jj]) {
        nums1[kk] = nums1[ii];
        ++k, ++i;
      } else {
        nums1[kk] = nums2[jj];
        ++k, ++j;
      }
    }
    while (j != n) {
      size_t jj = n - 1 - j, kk = m + n - 1 - k;
      nums1[kk] = nums2[jj];
      ++j, ++k;
    }
  }
};
