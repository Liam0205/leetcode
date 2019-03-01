static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int kthSmallest(const std::vector<std::vector<int>>& matrix, const int k) {
        const size_t sz = matrix.size();
        int lower = matrix[0][0];
        int upper = matrix[sz - 1][sz - 1];
        while (lower < upper) {
            size_t count = 0;
            const int middle = (lower + upper) / 2;
            for (const auto& row : matrix) {
                auto it = std::upper_bound(row.begin(), row.end(), middle);  // first element > middle
                count += std::distance(row.begin(), it);
            }
            if (count < k) {
                lower = middle + 1;  // count(lower - 1) < k
            } else {
                upper = middle;      // count(upper) >= k
            }
        }
        return upper;  // lower >= upper, hence count(lower) == count(upper) == k
    }
};

