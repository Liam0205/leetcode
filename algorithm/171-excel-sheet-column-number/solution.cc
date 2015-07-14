class Solution {
public:
    int titleToNumber(string s) {
        int int_result = 0;
        for (auto x : s) int_result = int_result * 26 + (x - 'A' + 1);
        return int_result;
    }
};
