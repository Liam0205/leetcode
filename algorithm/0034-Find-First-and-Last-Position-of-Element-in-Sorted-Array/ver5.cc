static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 private:
  const size_t kLongEnough = 16;

 public:
  std::vector<int> searchRange(const std::vector<int>& nums, const int target) {
    const size_t size = nums.size();
    size_t first = 0, last = size;
    while (first < last) {
      size_t mid = first + (last - first) / 2;
      if (target > nums[mid]) {
        first = mid + 1;
      } else if (target < nums[mid]) {
        last  = mid;
      } else {
        size_t lres = mid;
        size_t rres = mid;
        if (last - first > kLongEnough) {
          while (lres > 0 and nums[lres - 1] == target) {
              --lres;
          }
          while (rres + 1 < size and nums[rres + 1] == target) {
              ++rres;
          }
        } else {
          size_t lf = first, ll = mid, rf = mid, rl = last;
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
        }
        return {lres, rres};
      }
    }
    return {-1, -1};
  }
};

