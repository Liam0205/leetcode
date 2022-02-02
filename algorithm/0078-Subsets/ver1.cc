static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> work;
    res.reserve(std::pow(2, nums.size()));
    work.reserve(nums.size());
    backtracking(nums, 0, &work, &res);
    return res;
  }

 private:
  void backtracking(const std::vector<int>& nums, const size_t first, std::vector<int>* work,
                    std::vector<std::vector<int>>* res) {
    res->push_back(*work);
    const size_t sz = nums.size();
    for (size_t i = first; i != sz; ++i) {
      work->push_back(nums[i]);
      backtracking(nums, i + 1, work, res);
      work->pop_back();
    }
  }
};
