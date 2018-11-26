#include <iostream>
#include <vector>

class Solution {
public:
  int knightDialer(int N) {
    const int dirs[8][2] = {
      { 1, 2}, { 2, 1}, { 1, -2}, { 2, -1},
      {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}
    };
    const int MAX = 1e9 + 7;

    std::vector<std::vector<int>> dp(4, std::vector<int>(3, 1));
    dp[3][0] = dp[3][2] = 0;

    for (int k=1; k!=N; ++k) {
      std::vector<std::vector<int>> dp1(4, std::vector<int>(3, 0));

      // dp[k][i][j] = sum(dp[k-1][x][y]) for all (x, y)s that can move to (i, j)
      for (int i=0; i!=4; ++i) {
        for (int j=0; j!=3; ++j) {
          if (3 == i && j != 1) {
              continue;
          }
          for (auto m: dirs) {
            int x = i + m[0],
                y = j + m[1];
            if (x < 0 || x >= 4 || y < 0 || y >= 3) {
              // outbound, drop;
              continue;
            }
            dp1[i][j] = (dp[x][y] + dp1[i][j]) % MAX;
          }
        } // end of j
      } // end for i

      std::swap(dp1, dp);
    }

    int totSteps = 0;
    for (const auto& row: dp) {
      for (const auto elem: row) {
        totSteps = (elem + totSteps) % MAX;
      }
    }

    return totSteps % MAX;
  }
};
