class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        const size_t rowsz = A.size(), colsz = A[0].size();
        std::vector<std::vector<int>> B;
        B.resize(colsz);
        for (auto& row : B) {
            row.resize(rowsz);
        }
        for (size_t row = 0; row != colsz; ++row) {
            for (size_t col = 0; col != rowsz; ++col) {
                B[row][col] = A[col][row];
            }
        }
        return B;
    }
};
