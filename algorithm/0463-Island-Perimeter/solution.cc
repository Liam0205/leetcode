class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int res = 0;
        const size_t rowsz = grid.size();
        const size_t colsz = grid[0].size();
        for (int i = 0; i != rowsz; ++i) {
            for (int j = 0; j != colsz; ++j) {
                if (1 == grid[i][j]) {
                    res += 4;
                    if (j - 1 >= 0 and 1 == grid[i][j - 1]) {
                        res -= 2;
                    }
                    if (i - 1 >= 0 and 1 == grid[i - 1][j]) {
                        res -= 2;
                    }
                }
            }
        }
        return res;
    }
};

