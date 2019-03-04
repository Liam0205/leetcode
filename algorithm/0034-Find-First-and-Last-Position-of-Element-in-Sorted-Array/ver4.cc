static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, const int target) {
    const size_t size = nums.size();
    size_t first = 0, last = size;
    while (first < last) {
      size_t mid = first + (last - first) / 2;
      if (target > nums[mid]) {
        first = mid + 1;
      } else if (target < nums[mid]) {
        last  = mid;
      } else {
        size_t lsearch = mid;
        size_t rsearch = mid;
        while (lsearch > 0 and nums[lsearch - 1] == target) {
            --lsearch;
        }
        while (rsearch + 1 < size and nums[rsearch + 1] == target) {
            ++rsearch;
        }
        return {lsearch, rsearch};
      }
    }
    return {-1, -1};
  }
};

