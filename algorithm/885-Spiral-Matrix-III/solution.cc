class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r, int c) {
        std::vector<std::vector<int>> res = {{r, c}};
        res.reserve(R * C);
        int x = 0;
        int y = 1;
        int tmp;
        for (int n = 0; res.size() < R * C; ++n) {
            for (int i = 0; i < n / 2 + 1; ++i) {
                r += x;
                c += y;
                if (0 <= r and r < R and 0 <= c and c < C) {
                    res.push_back({r, c});
                }
            }
            tmp = x;
            x   = y;
            y   = -tmp;
        }
        return res;
    }
};
