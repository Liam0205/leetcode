class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (0 == grid.size()) {
            return 0;
        }
        int nRow = grid.size(),
            nCol = grid[0].size();
        
        for (int i=1; i!=nRow; ++i) {
            grid[i][0] += grid[i-1][0];
        }
        
        for (int i=1; i!=nCol; ++i) {
            grid[0][i] += grid[0][i-1];
        }
        
        for (int i=1; i!=nRow; ++i) {
            for (int j=1; j!=nCol; ++j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[nRow-1][nCol-1];
    }
};
