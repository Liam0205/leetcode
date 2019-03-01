static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int missingNumber(const std::vector<int>& nums) {
        const size_t sz = nums.size();
        int res = sz;
        for (size_t i = 0; i != sz; ++i) {
            res ^= i ^ nums[i];
        }
        return res;
    }
};

