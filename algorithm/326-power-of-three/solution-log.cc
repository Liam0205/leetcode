class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }
        double dou_tmp = log10(n) / log10(3);
        return (dou_tmp == floor(dou_tmp));
    }
};
