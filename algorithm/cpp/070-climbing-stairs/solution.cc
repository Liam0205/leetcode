class Solution {
public:
    int climbStairs(int n) {
        if (n < 1) return 0;
        else if (n == 1) return 1;
        else if (n == 2) return 2;
        vector<int> vec_int_fibonacci(n, 1);
        vec_int_fibonacci.at(1) = 2;
        for (size_t i = 2; i != n; ++i) {
            vec_int_fibonacci.at(i) = vec_int_fibonacci.at(i - 1) + vec_int_fibonacci.at(i - 2);
        }
        return vec_int_fibonacci.back();
    }
};
