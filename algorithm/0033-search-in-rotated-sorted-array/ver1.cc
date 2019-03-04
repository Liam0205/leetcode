static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int search(const vector<int>& nums, const int target) {
    const size_t idx = bsearch_with_fold(nums, bsearch_jump_offset(nums), target);
    return idx == nums.size() ? -1 : idx;
  }

 private:
  size_t bsearch_jump_offset(const vector<int>& nums) {
    const size_t size = nums.size();
    if (size < 2) {
      return 0;
    } else /* lbi */;
    size_t res = 0;
    const int back = nums.back();
    size_t first = 0, last = size;
    while (first < last) {
      size_t mid = first + (last - first) / 2;
      if (mid == 0 or nums[mid - 1] > nums[mid] and nums[mid] <= back) {
        return mid;
      } else if (nums[mid] > back) {
        first = mid + 1;
      } else {
        last = mid;
      }
    }
    return last;
  }

  size_t bsearch_with_fold(const vector<int>& nums, const size_t fold, const int target) {
    const size_t size = nums.size();
    if (size == 0) {
      return 0;
    } else if (size == 1) {
      if (nums[0] == target) {
        return 0;
      } else {
        return 1;
      }
    } else /* lbi */;
    size_t first = 0, last = size;
    while (first < last) {
      size_t mid = first + (last - first) / 2;
      size_t idx = (mid + fold) % size;
      if (nums[idx] < target) {
        first = mid + 1;
      } else if (nums[idx] > target) {
        last = mid;
      } else {
        return idx;
      }
    }
    return size;
  }
};

