class Solution {
public:
    int addDigits(int num) {
        return (num - (int) (9 * floor((num - 1) / 9)));
    }
};
