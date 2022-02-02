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

    int prev = std::numeric_limits<int>::min(), pprev = std::numeric_limits<int>::min();
    int slow = 0 /* to write */, fast = 0 /* to read */;
    for (; fast != sz; ++fast) {
      int c = nums[fast];
      if (c != prev || (c == prev && prev != pprev)) {
        pprev = prev;
        prev = c;
        nums[slow++] = c;
      } else {
        /* do nothing */
      }
    }
    return slow;
  }
};
