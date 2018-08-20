class Solution {
public:
    bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
		const int M = matrix.size();
        const int N = matrix[0].size();
        const int total = M + N - 1;
        const int len = std::max(M, N);

        for (int i = M - total; i != M; ++i) {
            bool recorded = false;
            int  record;
            for (int j = 0; j != len and j != N and i + j != M; ++j) {
                if (i + j >= 0) {
                    if (not recorded) {
                        record = matrix[i + j][j];
                        recorded = true;
                    } else {
                        if (record != matrix[i + j][j]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

