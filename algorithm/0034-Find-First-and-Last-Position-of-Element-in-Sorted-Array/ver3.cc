static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<int> searchRange(const std::vector<int>& nums, const int target) {
    const size_t size = nums.size();
    size_t first = 0, last = size;
    while (first < last) {
      size_t mid = first + (last - first) / 2;
      if (nums[mid] < target) {
        first = mid + 1;
      } else if (nums[mid] > target) {
        last = mid;
      } else {
        size_t lf = first, ll = mid, rf = mid, rl = last;
        size_t lres = ll, rres = rf;
        while (lf < ll) {
          size_t lm = lf + (ll - lf) / 2;
          if (nums[lm] < target) {
            lf = lm + 1;
          } else if (lm > 0 and nums[lm - 1] == target) {
            ll = lm;
          } else {
            lres = lm;
            break;
          }
        }
        while (rf < rl) {
          size_t rm = rf + (rl - rf) / 2;
          if (rm + 1 < size and nums[rm + 1] == target) {
            rf = rm + 1;
          } else if (nums[rm] > target) {
            rl = rm;
          } else {
            rres = rm;
            break;
          }
        }
        return {lres, rres};
      }
    }
    return {-1, -1};
  }
};

