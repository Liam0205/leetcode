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
        const int total_sum = sz * (sz + 1) / 2;
        const int curr_sum  = std::accumulate(nums.begin(), nums.end(), 0);
        return total_sum - curr_sum;
    }
};

