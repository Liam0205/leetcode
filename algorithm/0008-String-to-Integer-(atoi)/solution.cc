class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        if (!len) return 0; // empty string
        int idx = str.find_first_not_of(' ');
        int pmFlag = 1; // pm sign
        int result = 0;
        if (str[idx] == '+' || str[idx] == '-') {
            pmFlag = (str[idx++] == '-') ? -1 : 1;
        }
        // invalid input
        for (; idx != len && str[idx] >= '0' && str[idx] <= '9'; ++idx) {
            // overflow
            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && str[idx] - '0' > 7))
                return (pmFlag == 1) ? INT_MAX : INT_MIN;
            // normal calculation
            result = 10 * result + (str[idx] - '0');
        }
        return pmFlag * result;
    }
};
