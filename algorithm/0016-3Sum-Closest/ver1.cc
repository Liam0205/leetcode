static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
  int threeSumClosest(std::vector<int>& nums, const int target) {
    const size_t size = nums.size();
    if (size < 3) {
      return 0;
    } else /* lbi */;
    int res = nums[0] + nums[1] + nums[2];
    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i < size - 2; /* lbi */) {
      const int first = nums[i];
      for (size_t j = i + 1, k = size - 1; j < k; /* lbi */) {
        const int second = nums[j], third = nums[k];
        const int sum = first + second + third;
        res = (std::abs(target - sum) < std::abs(target - res)) ? sum : res;
        if (sum < target) {
          do { ++j; } while (j < k and second == nums[j]);
        } else if (sum > target) {
          do { --k; } while (j < k and third == nums[k]);
        } else {
          return res;
        }
      }
      do { ++i; } while (i < size and first == nums[i]);
    }
    return res;
  }
};

