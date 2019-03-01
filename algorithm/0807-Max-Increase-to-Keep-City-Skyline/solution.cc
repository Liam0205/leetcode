class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        std::vector<int> topsl, leftsl;
        getTopSkyline(grid, &topsl);
        getLeftSkyline(grid, &leftsl);
        int count = 0;
        auto length = grid.size();
        for (decltype(length) i = 0; i != length; ++i) {
            for (decltype(length) j = 0; j != length; ++j) {
                count += std::min(leftsl[i], topsl[j]) - grid[i][j];
            }
        }
        return count;
    }

    void getTopSkyline(const std::vector<std::vector<int>>& grid, std::vector<int>* skyline) {
        auto length = grid.size();
        skyline->clear();
        skyline->resize(length);
        for (decltype(length) i = 0; i != length; ++i) {
            for (decltype(length) j = 0; j != length; ++j) {
                skyline->operator[](i) = std::max(skyline->operator[](i), grid[j][i]);
            }
        }
    }

    void getLeftSkyline(const std::vector<std::vector<int>>& grid, std::vector<int>* skyline) {
        auto length = grid.size();
        skyline->clear();
        skyline->resize(length);
        for (decltype(length) i = 0; i != length; ++i) {
            for (decltype(length) j = 0; j != length; ++j) {
                skyline->operator[](i) = std::max(skyline->operator[](i), grid[i][j]);
            }
        }
    }
};
