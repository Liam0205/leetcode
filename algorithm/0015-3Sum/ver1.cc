static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    const size_t size = nums.size();
    std::vector<std::vector<int>> res;
    if (size < 3) {
      return res;
    } else /* lbi */;
    std::sort(nums.begin(), nums.end());
    if (nums[0] > 0 or nums[size - 1] < 0) {
      return res;
    } else if (nums[0] == 0 and nums[size - 1] == 0) {
      res.emplace_back(std::vector<int>{0, 0, 0});
      return res;
    } else /* lbi */;
    for (size_t i = 0; nums[i] <= 0 and i < size - 2; /* lbi */) {
      const int target = -nums[i];
      for (size_t j = i + 1, k = size - 1; j < k; /* lbi */) {
        const int low = nums[j], high = nums[k];
        const int sum = low + high;
        if (sum < target) {
          do { ++j; } while (j < k and low == nums[j]);
        } else if (sum > target) {
          do { --k; } while (j < k and high == nums[k]);
        } else {
          res.emplace_back(std::vector<int>{nums[i], low, high});
          do { ++j; } while (j < k and low == nums[j]);
          do { --k; } while (j < k and high == nums[k]);
        }
      }
      do { ++i; } while (i < size and -target == nums[i]);
    }
    return res;
  }
};

