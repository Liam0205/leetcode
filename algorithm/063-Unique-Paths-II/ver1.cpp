#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        auto dp(obstacleGrid);
        int nRow = dp.size(),
            nCol = dp[0].size();
        printGrid(dp);

        dp[0][0] = !dp[0][0];
        for(int i=1; i!=nRow; ++i){
          if (1 == dp[i][0] or 0 == dp[i-1][0]) {
            dp[i][0] = 0;
          } else {
            dp[i][0] = 1;
          }
        }
        
        for(int i=1; i!=nCol; ++i){
          if (1 == dp[0][i] or 0 == dp[0][i-1]) {
            dp[0][i] = 0;
          } else {
            dp[0][i] = 1;
          }
        }
        
        printGrid(dp);
        for (int i=1; i!=nRow; ++i) {
            for (int j=1; j!=nCol; ++j) {
                dp[i][j] = (1 == dp[i][j]) ? 0 : dp[i][j-1] + dp[i-1][j];
            }
        }

        printGrid(dp);
        return dp[nRow-1][nCol-1];
    }

private:
    void printGrid(const vector<vector<int>>& grid) {
      std::cout << "FOR DEBUG: \n";
      for (auto& row : grid) {
        for (auto e : row) {
          std::cout << " " << e;
        }
        std::cout << "\n";
      }
    }
};

using Grid = vector<vector<int>>;

int main(int argc, char* argv[]) {
  Grid grid;
  int nRow, nCol;
  std::cin >> nRow >> nCol;
  grid.resize(nRow, vector<int>(nCol, 0));
  for (int i=0; i!=nRow; ++i) {
    for (int j=0; j!=nCol; ++j) {
      std::cin >> grid[i][j];
    }
  }
  Solution sol;
  std::cout << sol.uniquePathsWithObstacles(grid) << std::endl;
  return 0;
}
