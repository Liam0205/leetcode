static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    if (nums.empty()) {
      return {{}};
    }
    std::sort(nums.begin(), nums.end());
    std::set<std::vector<int>> dedup;
    std::vector<int> tmp;
    dedup.insert(tmp);
    for (int i = 0; i != nums.size(); ++i) {
      backtracking(nums, i, &dedup, &tmp);
    }
    std::vector<std::vector<int>> res(dedup.begin(), dedup.end());
    return res;
  }

 private:
  void backtracking(const std::vector<int>& nums, const int first, std::set<std::vector<int>>* dedup,
                    std::vector<int>* tmp) {
    dedup->insert(*tmp);
    for (int i = first; i != nums.size(); ++i) {
      tmp->push_back(nums[first]);
      backtracking(nums, i + 1, dedup, tmp);
      tmp->pop_back();
    }
  }
};
