static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  bool search(const std::vector<int>& nums, const int target) {
    const size_t sz = nums.size();
    if (sz == 0) {
      return false;
    } else if (sz == 1) {
      return nums[0] == target;
    } else {
      return bsearch(nums, target) != sz;
    }
  }

 private:
  size_t bsearch(const std::vector<int>& nums, const int target) {
    size_t first = 0, last = nums.size() /* after tail */;
    while (first < last) {
      size_t mid = first + (last - first) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[first] == target) {
        return first;
      } else if (target == nums[last - 1]) {
        return last - 1;
      } else if (nums[first] == nums[mid] && nums[mid] == nums[last - 1]) {
        // first ... (mid, rotate point, target)? ... last
        // worst case: O(n).
        ++first, --last;
      } else if (nums[first] <= nums[mid]) /* mid is before rotate point */ {
        if (nums[first] <= target && target < nums[mid]) {
          // first ... target ... mid ... rotate point ... last
          last = mid;
        } else {
          // first ... mid ... target ... rotate point ... last
          first = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[last - 1]) {
          // first ... rotate point ... mid ... target ... last
          first = mid + 1;
        } else {
          // first ... rotate point ... target ... mid ... last
          last = mid;
        }
      }
    }
    return nums.size();
  }
};
