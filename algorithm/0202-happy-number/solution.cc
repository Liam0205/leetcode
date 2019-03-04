class Solution {
public:
    bool isHappy(int n) {
        if (n < 1) return false;
        if (n == 1) return true;
        int slow = n; int fast = n;
        do {
            slow = digitSquareSum (slow);
            fast = digitSquareSum (digitSquareSum (fast));
        } while (slow != fast);
        return (slow == 1);
    }
private:
    int digitSquareSum (int n) {
        int sum = 0;
        while (n > 0) {
            int curr_digit = n % 10;
            sum += curr_digit * curr_digit;
            n /= 10;
        }
        return sum;
    }
};
