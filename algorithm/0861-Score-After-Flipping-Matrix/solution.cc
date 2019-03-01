class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        const size_t colsz = A[0].size();
        const size_t rowsz = A.size();
        int res = 0;
        for (size_t col = 0; col != colsz; ++col) {
            res <<= 1;
            size_t cnt = 0;
            for (size_t row = 0; row != rowsz; ++row) {
                cnt += A[row][0] ^ A[row][col];
            }
            res += std::max(cnt, rowsz - cnt);
        }
        return res;
    }
};
