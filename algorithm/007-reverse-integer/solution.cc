class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        while (x) {
            int currentDigit = x % 10;
            result = result * 10 + currentDigit;
            if (result > INT_MAX || result < INT_MIN) return 0;
            x /= 10;
        }
        return result;
    }
};
