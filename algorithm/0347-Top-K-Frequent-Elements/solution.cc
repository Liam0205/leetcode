class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, size_t> counter;
        for (auto num : nums) {
            ++counter[num];
        }
        std::unordered_set<int>      uniqued(nums.begin(), nums.end());
        std::vector<int>             tmp(uniqued.begin(), uniqued.end());
        std::sort(tmp.begin(), tmp.end(), [counter](auto a, auto b) mutable { return counter[a] > counter[b]; });
        return std::vector<int>(tmp.begin(), tmp.begin() + k);
    }
};

