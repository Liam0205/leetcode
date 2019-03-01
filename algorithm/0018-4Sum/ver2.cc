static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
 public:
  std::vector<std::vector<int>> fourSum(std::vector<int>& nums, const int target) {
    const size_t size = nums.size();
    if (size < 4) {
      return {};
    } else /* lbi */;
    std::sort(nums.begin(), nums.end(), std::less<int>());
    std::vector<std::vector<int>> res;
    for (size_t i = 0;
        i < size - 3 and nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] <= target; /* lbi */) {
      const int first = nums[i];
      if (/* maxsum = */ nums[i] + nums[size - 3] + nums[size - 2] + nums[size - 1] >= target) {
        for (size_t j = i + 1; j < size - 2; /* lbi */) {
          const int second = nums[j];
          for (size_t k = j + 1, l = size - 1; k < l; /* lbi */) {
            const int third = nums[k], fourth = nums[l];
            const int sum   = first + second + third + fourth;
            if (sum < target) {
              do { ++k; } while (k < l and nums[k] == third);
            } else if (sum > target) {
              do { --l; } while (k < l and nums[l] == fourth);
            } else {
              res.emplace_back(std::vector<int>{first, second, third, fourth});
              do { ++k; } while (k < l and nums[k] == third);
              do { --l; } while (k < l and nums[l] == fourth);
            }
          }
          do { ++j; } while (j < size - 2 and nums[j] == second);
        }
      }
      do { ++i; } while (i < size - 3 and nums[i] == first);
    }
    return res;
  }
};
