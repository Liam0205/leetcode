static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int searchInsert(const std::vector<int>& nums, const int target) {
    size_t first = 0, last = nums.size();
    while (first < last) {
      int mid = first + (last - first) / 2;
      if (nums[mid] < target) {
        first = mid + 1;
      } else if (nums[mid] > target) {
        last  = mid;
      } else {
        return mid;
      }
    }
    return first;
  }
};

