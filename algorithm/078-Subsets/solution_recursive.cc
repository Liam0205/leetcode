class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> work;
        res.reserve(std::pow(2, nums.size()));
        work.reserve(nums.size());
        recursive(nums, 0, &work, &res);
        return res;
    }

private:
    void recursive(const std::vector<int>& nums,
                              const size_t first,
                         std::vector<int>* work,
            std::vector<std::vector<int>>* res) {
        res->push_back(*work);
        const size_t sz = nums.size();
        for (size_t i = first; i != sz; ++i) {
            work->push_back(nums[i]);
            recursive(nums, i + 1, work, res);
            work->pop_back();
        }
    }
};

