static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<int> searchRange(const std::vector<int>& nums, const int target) {
    const size_t size = nums.size();
    size_t first = 0, last = size;
    size_t l_first = first, m_mid = last, r_last = last;
    while (first < last) {
      size_t mid = first + (last - first) / 2;
      if (nums[mid] < target) {
        first = mid + 1;
      } else if (nums[mid] > target) {
        last = mid;
      } else {
        l_first = first;
        m_mid   = mid;
        r_last  = last;
        break;
      }
    }
    if (m_mid == size) {
      return {-1, -1};
    } else /* lbi */;
    size_t l_last = m_mid, l_res = m_mid;
    while (l_first < l_last) {
      size_t mid = l_first + (l_last - l_first) / 2;
      if (nums[mid] < target) {
        l_first = mid + 1;
      } else if (mid > 0 and nums[mid - 1] == target) {
        l_last  = mid;
      } else {
        l_res   = mid;
        break;
      }
    }
    size_t r_first = m_mid, r_res = m_mid;
    while (r_first < r_last) {
      size_t mid = r_first + (r_last - r_first) / 2;
      if (mid + 1 < size and nums[mid + 1] == target) {
        r_first = mid + 1;
      } else if (nums[mid] > target) {
        r_last  = mid;
      } else {
        r_res   = mid;
        break;
      }
    }
    return {l_res, r_res};
  }
};

