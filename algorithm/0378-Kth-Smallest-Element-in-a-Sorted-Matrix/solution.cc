static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int kthSmallest(const std::vector<std::vector<int>>& matrix, const int k) {
        const size_t rowsz = matrix.size();
        if (rowsz == 1) {
            return matrix[0][0];
        }
        std::vector<std::deque<int>> m;
        for (const auto& row : matrix) {
            m.push_back({row.begin(), row.end()});
        }
        for (int i = 0; i != k; ++i) {
            size_t row;
            bool is_smallest_initialized = false;
            int smallest;
            for (size_t j = 0; j != rowsz; ++j) {
                if (not m[j].empty()) {
                    if (not is_smallest_initialized) {
                        is_smallest_initialized = true;
                        smallest = m[j].front();
                        row      = j;
                    } else {
                        if (m[j].front() < smallest) {
                            smallest = m[j].front();
                            row      = j;
                        }
                    }
                }
            }
            if (i + 1 == k) {
                return smallest;
            } else {
                m[row].pop_front();
            }
        }
    }
};

