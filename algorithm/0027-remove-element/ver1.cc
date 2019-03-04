static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  int removeElement(vector<int>& nums, const int val) {
    return std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), val));
  }
};

