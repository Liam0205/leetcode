class Solution {
public:
    int getSum(int a, int b) {
        int res;
        while (b != 0) {
            res = a ^ b;         // semi-plus
            b   = (a & b) << 1;  // carry
            a   = res;
        }
        return res;
    }
};

