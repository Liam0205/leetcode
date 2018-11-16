class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        // N - NxN size of chessboard
        // K - number of steps knight moved
        // r&c - starts from (r, c)
        
        const int dirs[8][2] = {
            { 1, 2}, { 2, 1}, { 1,-2}, { 2,-1},
            {-1, 2}, {-2, 1}, {-1,-2}, {-2,-1}
        };
        
        vector<vector<double>> dp(N, vector<double>(N, 0));
        dp[r][c] = 1.0;
        
        for (int k=0; k!=K; ++k) {
            vector<vector<double>> dp1(N, vector<double>(N, 0));
            // dp[k][i][j] = sum(dp[k-1][x][y]) for all possible (x, y)s can move to (i, j).
            for (int i=0; i!=N; ++i) {
                for (int j=0; j!=N; ++j) {
                    for (int m=0; m!=8; ++m) {
                        int x = i + dirs[m][0];
                        int y = j + dirs[m][1];
                        if (x >= N || x < 0 || y >= N || y < 0) {
                            // outbound, drop;
                            continue;
                        }
                        dp1[i][j] += dp[x][y];
                    }
                }
            } // end for of i;
            swap(dp, dp1);
        }
        
        double totSteps = 0;
        for (const auto& row : dp) {
            for (const auto elem: row) {
                totSteps += elem;
            }
        }
        
        return static_cast<double>(totSteps) / pow(8, K);
    }
};
