class Solution {
public:
    int uniquePaths(int m, int n) {
        return nCr (m + n - 2, min(m, n) - 1);
    }
private:
    int nCr (int n, int r) {
        long long_result = 1;
        for (int i = 0; i != r; ++i) {
            // from n - r + 1 (when i = 0) to n (when i = r - 1)
            long_result *= (n - r + 1 + i);
            // from 1 (when i = 0)         to r (when i = r - 1)
            long_result /= (i + 1);
        }
        return (int) long_result;
    }
};
