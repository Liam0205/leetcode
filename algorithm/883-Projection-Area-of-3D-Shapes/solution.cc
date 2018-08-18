class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int cnt_xy = 0, cnt_yz = 0, cnt_zx = 0;
        const size_t rowsz = grid.size();
        const size_t colsz = grid[0].size();
        for (size_t row = 0; row != rowsz; ++row) {
            for (size_t col = 0; col != colsz; ++col) {
                const auto i = grid[row][col];
                cnt_xy += (i > 0 ? 1 : 0);
            }
            cnt_zx += *(std::max_element(grid[row].begin(), grid[row].end()));
        }
        for (size_t col = 0; col != colsz; ++col) {
            int tmp = grid[0][col];
            for (size_t row = 1; row != rowsz; ++row) {
                tmp = std::max(tmp, grid[row][col]);
            }
            cnt_yz += tmp;
        }
        return cnt_xy + cnt_yz + cnt_zx;
    }
};
