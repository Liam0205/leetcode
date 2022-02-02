static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    const int sz = nums.size();
    if (sz < 3) {
      return sz;
    }

    int slow = 2 /* to write */, fast = 2 /* to read */;
    for (; fast != sz; ++fast) {
      if (nums[fast] != nums[slow - 2]) {
        nums[slow++] = nums[fast];
      } else {
        /* do nothing */
      }
    }
    return slow;
  }
};
